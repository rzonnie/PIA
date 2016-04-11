#ifndef QUEUECONTROLLER_H
#define QUEUECONTROLLER_H

#include "../include/ReceivingSocket.h"
#include "../include/DynamicQueue.h"
#include "../include/Pia.h" 

class QueueController {
public:
    QueueController(BlockingQueue<std::string> *recq, std::map<uint32_t, std::pair<bool, char[1500]> > *defaultQueue, std::map<uint32_t, char[1500]> *ackQueue, int MQZ, int MPL);
    //Input: pointer to receiving, ack and default queues
    virtual ~QueueController();
    BlockingQueue<std::string> * getReceivingQueue();
    DynamicQueue getDynamicQueue();
    int getMaxQueueSize();
    int getMaxPacketLength();
    void pollDefaultQueue();
    void discardPacket();
private:
    //pointer to receivingQueue
    BlockingQueue<std::string> *recq;
    DynamicQueue dynamicQueue;
    Pia ReceivingPia(); //There are two instantiations of class PIA. This one is only used for receiving, the sending one is used in some other files.
    int MaxQueueSize;
    int MaxPacketLength;
};

#endif /* QUEUECONTROLLER_H */