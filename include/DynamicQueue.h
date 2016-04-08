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
#include <map>
#include <vector>
#include <thread>

/**
 * DynamicQueue will be used as a queueing algorithm for the sender. For now only
 * PIA packets are supported. Routing packets will be handled later on.
 */
class DynamicQueue {
public:
    DynamicQueue();
    virtual ~DynamicQueue();
    
    /**
     * Add a PIA specified packet to one of the queues. It is automatically determined
     * what type of packet it is
     * @param packet PIA
     */
    void addToQueue(PIA packet);
    
    std::vector<uint32_t>* getAckQueuedElements();
    std::vector<uint32_t>* getDefaultQueuedElements();
    
private:
    /**
     * This queue will queue all default packets, except from ack's. If the 
     * bool is set to true, it means an ack has been received for the previous packet
     * and it can thus be sent
     */
    std::map<uint32_t, std::pair<bool, char[1500]> > defaultQueue;
    
    /**
     * All sequence numbers inside the queue should be saved otherwise it is unknown
     * what packets are inside the queue
     */
    std::vector<uint32_t> defaultQueuedElements;
    
    /**
     * Make a seprate queue for all the acknowledgements
     */
    std::map<uint32_t, char[1500]> ackQueue;
    
    /**
     * All sequence numbers inside the queue should be saved otherwise it is unknown
     * what packets are inside the queue
     */
    std::vector<uint32_t> ackQueuedElements;
    
    /**
     * Necessary for thread locking
     */
    pthread_mutex_t mutex_queue;
    pthread_cond_t cond;
};

#endif /* DYNAMICQUEUE_H */

