/* 
 * File:   dynamicQueue.h
 * Author: Bart van der Scheer, Guido Kuijper, Olaf van der Meer and Remi Jonkman
 * Group: 9
 * 
 * Created on April 8, 2016, 9:02 AM
 */

#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include "PIA.h"
#include "Settings.h"
#include <map>
#include <vector>
#include <thread>
#include <algorithm>
#include <unistd.h>
#include <thread>
#include <chrono>

/**
 * DynamicQueue will be used as a queueing algorithm for the sender. For now only
 * PIA packets are supported. Routing packets will be handled later on.
 */
class DynamicQueue {
public:
    DynamicQueue();
    virtual ~DynamicQueue();
    
    /**
     * set on of the default queued elements send state
     * @param item uint
     * @param state bool
     */
    void setDefaultQueuedElements(uint item, bool state);

    /**
     * add a packet to the priority queue
     * @param packet PIA
     * @param sendState bool
     */
    void forwardPacket(PIA &packet, bool sendState);

    /**
     * Add a PIA specified packet to one of the queues. It is automatically determined
     * what type of packet it is
     * @param packet PIA
     * @param sendState bool
     */
    void push_back(PIA &packet, bool sendState = false);
    
    /**
     * Retrieve a packet from one of the sending queues
     * @return PIA packet
     */
    PIA retrievePacket();
    
    /**
     * Get the default queue size
     * @return size_t size
     */
    size_t size_default() const;
    
    /**
     * Get the ack queue size
     * @return size_t size
     */
    size_t size_ack() const;
    
    std::vector<uint32_t>* getAckQueuedElements();
    std::vector<std::pair<uint32_t, bool> >* getDefaultQueuedElements();
    
    /**
     * Erase a packet from the send queue because it is acknowledged.
     */
    void defaultQueueAck(uint32_t sequence);
    
    /**
     * Update the timestamp of a packet in the queue
     * @param uint32_t sequenceNumber
     * @param uint8_t timeout
     */
    void updateTimestamp(uint32_t sequenceNumber, uint32_t timeout);
    
    /**
     * Get the timestamp of a specific element in the queue
     * @param uint32_t sequenceNumber
     * @return uint32_t timestamp
     */
    double getTimestamp(uint32_t sequenceNumber);
    
    /**
     * Get the amount of time in milliseconds since the epoch
     * @return double
     */
    static double getTime();
    
    void removeDefaultPacket(PIA &packet);
    void removeDestination(uint32_t IP);

    void printDefaultQueue() const;
private:
    /**
     * This queue will queue all default packets, except from ack's. If the 
     * bool is set to true, it means an ack has been received for the previous packet
     * and it can thus be sent
     */
    std::map<uint32_t, std::pair<double, PIA> > defaultQueue;
    
    /**
     * All sequence numbers inside the queue should be saved otherwise it is unknown
     * what packets are inside the queue
     */
    std::vector<std::pair<uint32_t, bool> > defaultQueuedElements;
    
    /**
     * Make a seperate queue for all the special packets like acknowledgements and announcements
     */
    std::map<uint32_t, PIA> priorityQueue;
    
    /**
     * All sequence numbers inside the queue should be saved otherwise it is unknown
     * what packets are inside the queue
     */
    std::vector<uint32_t> priorityQueuedElements;
    
    /**
     * Necessary for thread locking
     */
    pthread_mutex_t mutex_queue;
};

#endif /* DYNAMICQUEUE_H */

