#include "../include/QueueController.h"

QueueController::QueueController(BlockingQueue<std::string> *recqin, int MQZ, int MPL, DynamicQueue DynamicQueueIn);
{
	//Hope I don't have to assign the
	recq = recqin;
	dynamicQueue = DynamicQueueIn;s
	MaxQueueSize = MQZ;
	MaxPacketLength = MPL;
}

QueueController::~QueueController() {};
	
BlockingQueue<std::string> * getReceivingQueue() 
{
	return recq;
}
	
DynamicQueue QueueController::getDynamicQueue()
{
	return dynamicQueue;
}
	
int QueueController::getMaxQueueSize() 
{
	return MaxQueueSize;
}
	
int QueueController::getMaxPacketLength() 
{
	return MaxPacketLength
}
	
uint32_t QueueController::pollDefaultQueue() 
{
	return (dynamicQueue.getFirstDefaultQueueElement);
}
	
void QueueController:: queueSizeChecker()
{
	if (dynamicQueue.getDefaultQueuedElements()->defaultQueuedElements.size() > MaxQueueSize)
	{
		//Get number of top packet, then destroy that one. Call queueSizeChecker() again.
	}
}

void QueueController::ackChecker(uint32_t seqNumber)
{
	if (seqNumber == ReceivingPia.readData()
