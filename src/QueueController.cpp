#include "../include/QueueController.h"

QueueController::QueueController(Settings* settings, DynamicQueue* sendQueue, DynamicQueue* receivingQueue, RoutingTable* routingTable)
: ThreadRunner(settings), sendQueue(sendQueue), receivingQueue(receivingQueue), routingTable(routingTable) {
    //MaxQueueSize = MQZ;
    //MaxPacketLength = MPL;
}

QueueController::~QueueController() {
};

void QueueController::run() {
    int cnt = 0;
    while (true) {
        try {
            if (receivingQueue->size_ack() > 0 || receivingQueue->size_default() > 0) {
                PIA packet = receivingQueue->retrievePacket();

                //Check for NTA
                if (packet.isNta()) {
                    ntaProcessor(packet);
                }//Check for ACK
                else if (packet.isAck()) {
                    ackChecker(packet);
                } else if (receivingQueue->size_default() > 0) {
                    //It is probably a data packet

                    //1. Interpret it
                    defaultProcessor(packet);

                    //2. Send an ACK
                    sendAck(packet);
                }
            }
        } catch (exception &e) {
            std::cout << e.what() << std::endl;
        }

        if (cnt > 25000) {
            routingTable->tagFallouts();
            routingTable->printRoutingTable();
            cnt = 0;
        }
        cnt++;
        usleep(50);
    }

}

std::vector<std::string> QueueController::packetSplitter(std::string chatpayload) {
    // Create result and temp vectors/strings. Push contents of chatpayload in temp and pushback temp onto result whenever size of temp is MTU.
    std::vector<std::string> result;
    std::string temp;
    unsigned int iterator = 0;
    while (iterator < chatpayload.size()) {
        if (temp.size() == settings->getMTU()) {
            result.push_back(temp);
            temp = "";
        }
        temp = temp + chatpayload[iterator];
    }
    //Also send the last few bits of data from chatpayload
    result.push_back(temp);
    return result;
}

std::vector<PIA> QueueController::packetCreator(uint32_t destinationIP, uint32_t SequenceNumber, uint32_t AckNumber, bool ACK, bool NTA, std::vector<std::string> result) {
    //Creates packets based on input variables.
    std::vector<PIA> PIAPackets;
    for (auto i : result) {
        PIA newPIAPacket(destinationIP, SequenceNumber, AckNumber, false, false, "Payload");
        PIAPackets.push_back(newPIAPacket);
    }
    return PIAPackets;
}

void QueueController::packetPusher(PIA &packet) {
}

uint32_t QueueController::sequenceNumberGenerator() {
    //SeqNumber 1 high than previous or not
}

void QueueController::sendAck(PIA &packet) {

    PIA ackPacket(settings->getLocalIP(), //IPaddr
            packet.getSourceAddress(), //IPaddr
            0, //sequencenr
            packet.getSequenceNumber() + 1, //acknr
            true, //ACK flag
            false, //NTA flag
            "hi" //payload
            );
    sendQueue->push_back(ackPacket, true);
}

void QueueController::ntaProcessor(PIA &packet) {
    // Create a temporary RoutingTable
    RoutingTable temp;
    // Open an input stringstream
    std::istringstream payload(packet.getPayload());

    // Interpret the archive information inside the stream
    boost::archive::text_iarchive archive(payload);

    // Stream the archive to the temporary routing table
    archive >> temp;

    //temp.printRoutingTable();
    // Now update the actual routing table
    routingTable->updateRoutingTable(temp);

    //std::cout << "Routing table updated by host: ";
    //printIP(temp.getMyIdentifier());
    //std::cout << temp.getMyIdentifier() << std::endl;
}

void QueueController::ackChecker(PIA &packet) {
    //all seq numbers before the sequence numbers need to be deleted from the queue

    uint32_t ackNumber = packet.getAcknowledgementNumber();
    //remove the entry from sending queue, because it is successfully received
    sendQueue->defaultQueueAck(ackNumber);
}

void QueueController::defaultProcessor(PIA& packet) {
    std::cout << "Packet Payload: " << packet.getPayload() << std::endl;
    receivingQueue->removeDefaultPacket(packet);
}
