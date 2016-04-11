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
	
int QueueController::getMaxQueueSize() 
{
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
