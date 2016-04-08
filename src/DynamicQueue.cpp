/* 
 * File:   dynamicQueue.cpp
 * Author: Bart van der Scheer, Guido Kuijper, Olaf van der Meer and Remi Jonkman
 * Group: 9
 * 
 * Created on April 8, 2016, 9:02 AM
 */

#include "../include/DynamicQueue.h"
#include <arpa/inet.h>

DynamicQueue::DynamicQueue() {
}

DynamicQueue::~DynamicQueue() {
}

void DynamicQueue::push_back(PIA packet, bool sendState) {
    // Locking Thread
    std::cout << "push_back: Locking Thread" << std::endl;
    pthread_mutex_lock(&mutex_queue);
    std::cout << "Inserting an item" << std::endl;

    if (packet.isAck()) {
        ackQueue.insert(std::make_pair(packet.getAcknowledgementNumber(), packet));
        std::cout << "Before adding: " << ackQueuedElements.size() << std::endl;
        ackQueuedElements.push_back(packet.getAcknowledgementNumber());
        std::cout << "After adding: " << ackQueuedElements.size() << std::endl;
        //std::cout << "Added a packet! " << "Size: " << ackQueue.size() << std::endl;
    } else {
        defaultQueue.insert(std::make_pair(packet.getSequenceNumber(), packet));
        defaultQueuedElements.push_back(std::make_pair(packet.getSequenceNumber(), sendState));
        //std::cout << "Added a packet! " << "Size: " << defaultQueue.size() << std::endl;
    }

    std::cout << "push_back: unlocking mutex" << std::endl;
    pthread_mutex_unlock(&mutex_queue);
}

PIA DynamicQueue::retrievePacket() {
    PIA packet;
    std::cout << "pop: locking mutex" << std::endl;
    pthread_mutex_lock(&mutex_queue);
    
    if (!ackQueue.empty()) {
        std::cout << "Not going here " << ackQueuedElements.size() << std::endl;
        //packet = ackQueue[ackQueuedElements[0]];
         packet = PIA(
            inet_addr("192.168.5.1"), //IPaddr
            100, //sequencenr
            20, //acknr
            true, //ACK flag
            true, //NTA flag
            "hi there" //payload
            );
        
        //ackQueue.erase(ackQueuedElements[0]);
        //ackQueuedElements.erase(ackQueuedElements.begin());
    } else if (!defaultQueuedElements.empty()) {
        for (auto element : defaultQueuedElements) {
            if (element.second) {
                packet = defaultQueue[element.first];
            }
        }
    }
    
    std::cout << "Ack number: " << packet.getAcknowledgementNumber() << std::endl;
    std::cout << defaultQueuedElements.size() << std::endl;
    
    std::cout << "POP - unlocking mutex" << std::endl;
    pthread_mutex_unlock(&mutex_queue);
    return packet;
}

size_t DynamicQueue::size_default() const {
    return this->defaultQueue.size();
}

size_t DynamicQueue::size_ack() const {
    return this->ackQueue.size();
}

std::vector<uint32_t>* DynamicQueue::getAckQueuedElements() {
    return &ackQueuedElements;
}

std::vector<std::pair<uint32_t, bool> >* DynamicQueue::getDefaultQueuedElements() {
    return &defaultQueuedElements;
}

