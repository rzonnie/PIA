#include "../include/QueueController.h"

QueueController::QueueController(int MQZ, int MPL, DynamicQueue sendQueue, DynamicQueue receivingQueue)
{
	this->sendQueue = sendQueue;
	this->receivingQueue = receivingQueue;
	MaxQueueSize = MQZ;
	MaxPacketLength = MPL;
}

QueueController::~QueueController() {};

void QueueController::run(){

}

int QueueController::getMaxQueueSize() {
    return MaxQueueSize;
}

int QueueController::getMaxPacketLength() 
{
	return MaxPacketLength;
}
	
uint32_t QueueController::pollDefaultQueue() 
{
	//return (sendQueue.getDefaultQueuedElements());
}
	
void QueueController::queueSizeChecker()
{
	/*

	if (sendQueue.getDefaultQueuedElements()->defaultQueuedElements.size() > MaxQueueSize)
	{
		//Get number of top packet, then destroy that one. Call queueSizeChecker() again.
	}
	*/
}

void QueueController::ntaChecker(PIA &packet) {
        // Create a temporary RoutingTable
        RoutingTable temp;
        
        // Open an input stringstream
        std::istringstream payload(packet.getPayload());
        
        // Interpret the archive information inside the stream
        boost::archive::text_iarchive archive(payload);
        
        // Stream the archive to the temporary routing table
        archive >> temp;
        
        // Now update the actual routing table
        routingTable->updateRoutingTable(temp);
        
        std::cout << "Routing table updated by host: ";
        printIP(temp.getMyIdentifier());
}

void QueueController::ackChecker(){

	//receivingQueue.
}
