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
        std::cout << "Queue controller: retrieving packets" << std::endl;
        PIA packet = receivingQueue->retrievePacket();

        if (packet.isNta())
            ntaChecker(packet);
        
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

    // Now update the actual routing table
    std::cout << "Temp Check: " << routingTable->getRoutingTable().size() << std::endl;
    routingTable->updateRoutingTable(temp);

    //std::cout << "Routing table updated by host: ";
    //printIP(temp.getMyIdentifier());
    //std::cout << temp.getMyIdentifier() << std::endl;
    routingTable->printRoutingTable();
}

void QueueController::ackChecker(PIA &packet){
	uint32_t seqNumber = packet.getAcknowledgementNumber();
	//sendQueue->
}
