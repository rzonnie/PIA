#ifndef QUEUECONTROLLER_H
#define QUEUECONTROLLER_H

#include "ReceivingSocket.h"
#include "DynamicQueue.h"
#include "PIA.h"
#include "functions.h"

class QueueController : public ThreadRunner {
public:
    QueueController(Settings* settings, DynamicQueue* sendQueue, DynamicQueue* receivingQueue);
    //Input: pointer to receiving, ack and default queues
    virtual ~QueueController();
    
    void discardPacket();
    void run() override;

private:
    void ntaChecker(PIA &packet);
    
    DynamicQueue* sendQueue;
    DynamicQueue* receivingQueue;
    RoutingTable* routingTable;
};

#endif /* QUEUECONTROLLER_H */