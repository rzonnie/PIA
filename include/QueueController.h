#ifndef QUEUECONTROLLER_H
#define QUEUECONTROLLER_H

#include "ReceivingSocket.h"
#include "DynamicQueue.h"
#include "PIA.h"

#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class QueueController : public ThreadRunner {
public:
    QueueController(Settings* settings, DynamicQueue* sendQueue, DynamicQueue* receivingQueue, RoutingTable* routingTable);
    //Input: pointer to receiving, ack and default queues
    virtual ~QueueController();
    
    void discardPacket();
    void run() override;
    void ackChecker(PIA &packet);
    void sendAck(PIA &packet);

private:
    void ntaChecker(PIA &packet);
    
    DynamicQueue* sendQueue;
    DynamicQueue* receivingQueue;
    RoutingTable* routingTable;
};

#endif /* QUEUECONTROLLER_H */
