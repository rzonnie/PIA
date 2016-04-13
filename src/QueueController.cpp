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
                    ackProcessor(packet);
                } else if (receivingQueue->size_default() > 0) {
                    //It is probably a data packet

                    //Multihop
                    if (packet.getDestinationAddress() == settings->getLocalIP()) {
                        //1. Interpret it
                        defaultProcessor(packet);
                        //2. Send an ACK
                        sendAck(packet);
                    }//retransmit it to the next node
                    else {
                        //receivingQueue->removeDefaultPacket(packet);
                        sendQueue->forwardPacket(packet, true);
                    }
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

void QueueController::sendData(std::string chatpayload, uint32_t destinationIP) {
    //Split the input into multiple strings
    // Create result and temp vectors/strings. Push contents of chatpayload in temp and pushback temp onto result whenever size of temp is MTU.
    std::vector<std::string> result;
    std::string temp;
    unsigned int index = 0;
    while (index < strlen(chatpayload.c_str())) {
        // subtract the header size of 20 bytes
        if (temp.size() == settings->getMTU() - 20) {
            result.push_back(temp);
            temp = "";
        }
        temp = temp + chatpayload[index];
        index++;
    }
    
    //Also send the last few bits of data from chatpayload
    result.push_back(temp);

    //Create packets from the strings
    std::vector<PIA> PIAPackets;
    int i;
    for (i = 0; i < result.size(); i++) {
        PIA newPIAPacket(settings->getLocalIP(), destinationIP, 100 + i, 0, false, false, result[i]);
        PIAPackets.push_back(newPIAPacket);
    }
    //send the packets
    sendPackets(PIAPackets);

    std::cout << "created " << result.size() << " packets\n";
}

void QueueController::sendPackets(std::vector<PIA> &packets) {

    //Add all the packets to the queue
    for (auto packet : packets) {
        sendQueue->push_back(packet, false);
    }

    //Set the first item in the send queue to true.
    sendQueue->setDefaultQueuedElements(0, true);
}

uint32_t QueueController::sequenceNumberGenerator() {
    return rand() % RAND_MAX;
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

void QueueController::ackProcessor(PIA &packet) {
    //all seq numbers before the sequence numbers need to be deleted from the queue

    uint32_t ackNumber = packet.getAcknowledgementNumber();
    //remove the entry from sending queue, because it is successfully received
    sendQueue->defaultQueueAck(ackNumber);

    //Set the first item in the send queue to true.
    sendQueue->setDefaultQueuedElements(0, true);
}

void QueueController::defaultProcessor(PIA& packet) {
    packet.printPacket(true);
    receivingQueue->removeDefaultPacket(packet);
}
