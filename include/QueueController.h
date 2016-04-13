#ifndef QUEUECONTROLLER_H
#define QUEUECONTROLLER_H


#include "ReceivingSocket.h"
#include "DynamicQueue.h"
#include "PIA.h"
#include "functions.h"

#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class QueueController : public ThreadRunner {
public:
    QueueController(Settings* settings, DynamicQueue* sendQueue, DynamicQueue* receivingQueue, RoutingTable* routingTable);
    //Input: pointer to receiving, ack and default queues
    virtual ~QueueController();
    
    //Add some payload to the sending queue
    void sendData(std::string chatpayload, uint32_t destinationIP);

    void discardPacket();
    
    void setTimestamp();
    void run() override;

private:
    /**
     * Send packets from the vector and sets the first entry in the sending queue
     * to true (ready to send).
     */
    void sendPackets(std::vector<PIA> &packets);

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
