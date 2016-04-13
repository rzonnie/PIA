/* 
 * File:   dynamicQueue.cpp
 * Author: Bart van der Scheer, Guido Kuijper, Olaf van der Meer and Remi Jonkman
 * Group: 9
 * 
 * Created on April 8, 2016, 9:02 AM
 */

#include "../include/DynamicQueue.h"

DynamicQueue::DynamicQueue() {
    pthread_mutex_init(&mutex_queue, NULL);
}

DynamicQueue::~DynamicQueue() {
}

double DynamicQueue::getTime() {
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    auto timeSinceEpoch = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
    return (double) timeSinceEpoch;
}

void DynamicQueue::push_back(PIA &packet, bool sendState) {
    // Locking Thread
    //std::cout << "push_back: Locking Thread" << std::endl;
    if (packet.getDestinationAddress() > 0) {
        pthread_mutex_lock(&mutex_queue);

        // Check whether it is an ack or nta packet with high priority
        if (packet.isAck() || packet.isNta()) {
            if (priorityQueue.count(packet.getAcknowledgementNumber()) < 1) {
                priorityQueue.insert(std::make_pair(packet.getAcknowledgementNumber(), packet));
                priorityQueuedElements.push_back(packet.getAcknowledgementNumber());
            }
        } else if (packet.getDestinationAddress() > 0) {
            if (defaultQueue.count(packet.getSequenceNumber()) < 1) {

                defaultQueue.insert(std::make_pair(packet.getSequenceNumber(), std::make_pair(getTime(), packet)));

                defaultQueuedElements.push_back(std::make_pair(packet.getSequenceNumber(), sendState));
                //std::cout << "Added a packet! " << "Size: " << defaultQueue.size() << std::endl;
            }
        }

        //std::cout << "push_back: unlocking mutex" << std::endl;
        pthread_mutex_unlock(&mutex_queue);
    }
}

PIA DynamicQueue::retrievePacket() {
    PIA packet;
    //std::cout << "pop: locking mutex" << std::endl;
    pthread_mutex_lock(&mutex_queue);

    if (!priorityQueue.empty()) {
        packet = priorityQueue[priorityQueuedElements[0]];
        priorityQueue.erase(priorityQueuedElements[0]);
        priorityQueuedElements.erase(priorityQueuedElements.begin());
        std::cout << "Removed from queue" << size_default() << std::endl;
    } else if (defaultQueuedElements.size() > 0) {
        for (auto element : defaultQueuedElements) {
            if (element.second) {
                packet = defaultQueue[element.first].second;
            }
        }
    }

    //std::cout << "pop: unlocking mutex" << std::endl;
    pthread_mutex_unlock(&mutex_queue);
    return packet;
}

void DynamicQueue::defaultQueueAck(uint32_t sequence) {
    //std::cout << "pop: ack locking mutex" << std::endl;
    pthread_mutex_lock(&mutex_queue);

    defaultQueue.erase(sequence - 1);
    std::pair<uint32_t, bool> temp(sequence - 1, false);
    std::pair<uint32_t, bool> temp2(sequence - 1, true);

    auto it = std::find(defaultQueuedElements.begin(), defaultQueuedElements.end(), temp);
    auto it2 = std::find(defaultQueuedElements.begin(), defaultQueuedElements.end(), temp2);
    if (it != defaultQueuedElements.end()) defaultQueuedElements.erase(it);
    if (it2 != defaultQueuedElements.end()) defaultQueuedElements.erase(it2);

    //std::cout << "pop: ack unlocking mutex" << std::endl;
    pthread_mutex_unlock(&mutex_queue);
}

void DynamicQueue::removeDefaultPacket(PIA& packet) {
    //std::cout << "pop: locking mutex" << std::endl;
    pthread_mutex_lock(&mutex_queue);
    std::pair<uint32_t, bool> temp(packet.getSequenceNumber(), true);

    defaultQueue.erase(packet.getSequenceNumber());

    auto it = std::find(defaultQueuedElements.begin(), defaultQueuedElements.end(), temp);
    if (it != defaultQueuedElements.end()) defaultQueuedElements.erase(it);

    std::cout << "Removed an element!" << std::endl;
    //std::cout << "POP - unlocking mutex" << std::endl;
    pthread_mutex_unlock(&mutex_queue);
}

void DynamicQueue::updateTimestamp(uint32_t sequenceNumber, uint32_t timeout) {
    pthread_mutex_lock(&mutex_queue);
    if (defaultQueue.size() > 0 && defaultQueue.find(sequenceNumber) != defaultQueue.end()) {
        std::cout << "Updating timestamp" << std::endl;
        defaultQueue[sequenceNumber].first = getTime() + timeout;
    }
    pthread_mutex_unlock(&mutex_queue);
}

double DynamicQueue::getTimestamp(uint32_t sequenceNumber) {
    double timestamp = 0;
    pthread_mutex_lock(&mutex_queue);
    if (defaultQueue.find(sequenceNumber) != defaultQueue.end())
        timestamp = defaultQueue[sequenceNumber].first;
    pthread_mutex_unlock(&mutex_queue);
    return timestamp;
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

void DynamicQueue::printDefaultQueue() const {
    for (auto element : defaultQueue) {
        std::cout << "Seq number: " << element.first;
        element.second.second.printPacket(true);
    }
}

