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
        //std::cout<< "Queue controller: sending packets\n";

        //std::cout << "Queue controller: retrieving packets" << std::endl;
        PIA packet = receivingQueue->retrievePacket();

        //Check for NTA
        if (packet.isNta()) {
            ntaProcessor(packet);
        }            //Check for ACK
        else if (packet.isAck()) {
            ackChecker(packet);
        } else {
            //It is probably a data packet

            //1. Interpret it
            defaultProcessor(packet);
            
            //2. Send an ACK
            sendAck(packet);
        }

        if (cnt > 25000) {
            routingTable->tagFallouts();
            routingTable->printRoutingTable();
            cnt = 0;
        }
        cnt++;

        //std::cout << "Queue controller: sleep 1 second" << std::endl;
        usleep(50);
    }
}

void QueueController::sendAck(PIA &packet) {
    //packet.getSourceAddress();
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
    uint32_t ackNumber = packet.getAcknowledgementNumber();
    //remove the entry from sending queue, because it is successfully received
    sendQueue->defaultQueueAck(ackNumber);
}

void QueueController::defaultProcessor(PIA& packet) {
    
}