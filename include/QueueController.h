#ifndef QUEUECONTROLLER_H
#define QUEUECONTROLLER_H


#include "ReceivingSocket.h"
#include "DynamicQueue.h"
#include "PIA.h"
#include "functions.h"
#include "ChatHistory.h"

#include <stdlib.h>
#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class GUIController;

class QueueController : public ThreadRunner {
public:
    QueueController(Settings* settings, DynamicQueue* sendQueue, DynamicQueue* receivingQueue, RoutingTable* routingTable, ChatHistory* chatHistory);
    //Input: pointer to receiving, ack and default queues
    virtual ~QueueController();
    
    /**
	 * Send some payload to the destination address, the input string is split into multiple
	 * packets which are then added to the sending queue.
	 * @param chatpayload std::string
	 * @param destinationIP uint32_t
	 */
    void sendData(std::string chatpayload, uint32_t destinationIP);
    
    /**
	 * Generate a sequence number
	 */
    uint32_t sequenceNumberGenerator();

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

    ChatHistory* chatHistory;
    DynamicQueue* sendQueue;
    DynamicQueue* receivingQueue;
    RoutingTable* routingTable;
};

#endif /* QUEUECONTROLLER_H */
