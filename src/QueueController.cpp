#include "../include/QueueController.h"

QueueController::QueueController(Settings* settings, DynamicQueue* sendQueue, DynamicQueue* receivingQueue, RoutingTable* routingTable)
: ThreadRunner(settings), sendQueue(sendQueue), receivingQueue(receivingQueue), routingTable(routingTable) {
    //MaxQueueSize = MQZ;
    //MaxPacketLength = MPL;
}

QueueController::~QueueController() {
};

void QueueController::run() {
    while (true) {
        //routingTable->printRoutingTable();
        std::cout << "Queue controller: retrieving packets" << std::endl;
        PIA packet = receivingQueue->retrievePacket();

        if (packet.isNta()){
            ntaChecker(packet);
        }
        
        std::cout << "Queue controller: sleep 1 second" << std::endl;
        sleep(1);
    }
}

void QueueController::ntaChecker(PIA &packet) {
    std::cout << "Still alive" << std::endl;
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
    routingTable->printRoutingTable();

    //std::cout << "Routing table updated by host: ";
    //printIP(temp.getMyIdentifier());
    //std::cout << temp.getMyIdentifier() << std::endl;
}

void QueueController::ackChecker(PIA &packet){
	uint32_t seqNumber = packet.getAcknowledgementNumber();
	//std::cout <<"hi \n"<< sendQueue->getDefaultQueuedElements();
}
