#ifndef QUEUECONTROLLER_H
#define QUEUECONTROLLER_H


#include "ReceivingSocket.h"
#include "DynamicQueue.h"
#include "PIA.h"
#include "functions.h"

#include <stdlib.h>
#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class QueueController : public ThreadRunner {
public:
    QueueController(Settings* settings, DynamicQueue* sendQueue, DynamicQueue* receivingQueue, RoutingTable* routingTable);
    //Input: pointer to receiving, ack and default queues
    virtual ~QueueController();
    
    std::vector<PIA> packetCreator(uint32_t destinationIP, uint32_t SequenceNumber, uint32_t AckNumber, bool ACK, bool NTA, std::vector<std::string> result);
    std::vector<std::string> packetSplitter(std::string chatpayload);
    void sendData(PIA &packet);
    uint32_t sequenceNumberGenerator();
    void setTimestamp();
    void run() override;

private:
    /**
     * If the received packet is an announcement, execute this code to update the 
     * routing table
     * @param packet PIA the packet you want to process
     */
    void ntaProcessor(PIA &packet);
    
    /**
     * If the received packet is an acknowledgement, this code will do all things you
     * want. 
     * @param packet PIA the packet you want to process
     */
    void ackProcessor(PIA &packet);
    
    /**
     * Send an ack for the packet in the parameter
     * @param packet PIA
     */
    void sendAck(PIA &packet);
    
    /**
     * If the packet is a normal data packet, use this function.
     * @param packet PIA a normal data packet
     */
    void defaultProcessor(PIA &packet);
    
    uint32_t sequenceNumberGenerator();
    
    DynamicQueue* sendQueue;
    DynamicQueue* receivingQueue;
    RoutingTable* routingTable;
};

#endif /* QUEUECONTROLLER_H */
