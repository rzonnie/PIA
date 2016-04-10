/* 
 * File:   dynamicQueue.cpp
 * Author: Bart van der Scheer, Guido Kuijper, Olaf van der Meer and Remi Jonkman
 * Group: 9
 * 
 * Created on April 8, 2016, 9:02 AM
 */

#include <algorithm>

#include "../include/DynamicQueue.h"

DynamicQueue::DynamicQueue() {
    pthread_mutex_init(&mutex_queue, NULL);
}

DynamicQueue::~DynamicQueue() {
}

void DynamicQueue::push_back(PIA &packet, bool sendState) {
    // Locking Thread
    //std::cout << "push_back: Locking Thread" << std::endl;
    pthread_mutex_lock(&mutex_queue);

    if (packet.isAck() || packet.isNta()) {
        if (priorityQueue.count(packet.getAcknowledgementNumber()) < 1) {
            priorityQueue.insert(std::make_pair(packet.getAcknowledgementNumber(), packet));
            priorityQueuedElements.push_back(packet.getAcknowledgementNumber());
            //std::cout << "Added a packet! " << "Size: " << ackQueue.size() << std::endl;
        }
    } else {
        if (defaultQueue.count(packet.getSequenceNumber()) < 1) {
            defaultQueue.insert(std::make_pair(packet.getSequenceNumber(), packet));
            defaultQueuedElements.push_back(std::make_pair(packet.getSequenceNumber(), sendState));
            //std::cout << "Added a packet! " << "Size: " << defaultQueue.size() << std::endl;
        }
    }

    //std::cout << "push_back: unlocking mutex" << std::endl;
    pthread_mutex_unlock(&mutex_queue);
}

PIA DynamicQueue::retrievePacket() {
    PIA packet;
    //std::cout << "pop: locking mutex" << std::endl;
    pthread_mutex_lock(&mutex_queue);

    if (!priorityQueue.empty()) {
        packet = priorityQueue[priorityQueuedElements[0]];
        priorityQueue.erase(priorityQueuedElements[0]);
        priorityQueuedElements.erase(priorityQueuedElements.begin());
    } else if (!defaultQueuedElements.empty()) {
        for (auto element : defaultQueuedElements) {
            if (element.second) {
                packet = defaultQueue[element.first];
            }
        }
    }

    //std::cout << "POP - unlocking mutex" << std::endl;
    pthread_mutex_unlock(&mutex_queue);
    return packet;
}

size_t DynamicQueue::size_default() const {
    return this->defaultQueue.size();
}

size_t DynamicQueue::size_ack() const {
    return this->priorityQueue.size();
}

std::vector<uint32_t>* DynamicQueue::getAckQueuedElements() {
    return &priorityQueuedElements;
}

std::vector<std::pair<uint32_t, bool> >* DynamicQueue::getDefaultQueuedElements() {
    return &defaultQueuedElements;
}

