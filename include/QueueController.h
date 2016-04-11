#ifndef QUEUECONTROLLER_H
#define QUEUECONTROLLER_H

#include "../include/ReceivingSocket.h"
#include "../include/DynamicQueue.h"
#include "../include/PIA.h"


class QueueController : public ThreadRunner
{
	public:
		QueueController(int MQZ, int MPL, DynamicQueue sendQueue, DynamicQueue receivingQueue);
		//Input: pointer to receiving, ack and default queues
		virtual ~QueueController();
		int getMaxQueueSize();
		int getMaxPacketLength();
		uint32_t pollDefaultQueue();
		void discardPacket();
		void queueSizeChecker();
		void run() override;

	private:
		DynamicQueue sendQueue;
		DynamicQueue receivingQueue;
		int MaxQueueSize;
		int MaxPacketLength;
		RoutingTable* routingTable;
};

#endif /* QUEUECONTROLLER_H */
