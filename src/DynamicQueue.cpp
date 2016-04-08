/* 
 * File:   dynamicQueue.cpp
 * Author: Bart van der Scheer, Guido Kuijper, Olaf van der Meer and Remi Jonkman
 * Group: 9
 * 
 * Created on April 8, 2016, 9:02 AM
 */

#include "../include/DynamicQueue.h"

DynamicQueue::DynamicQueue() {
}

DynamicQueue::~DynamicQueue() {
}

void DynamicQueue::addToQueue(PIA packet) {
    if (packet.isAck()) {
        packet.getData(ackQueue[packet.getAcknowledgementNumber()]);
        ackQueuedElements.push_back(packet.getAcknowledgementNumber());
        //std::cout << "Added a packet! " << "Size: " << ackQueue.size() << std::endl;
    } else {
        std::pair<bool, char[1500] > secondPair;
        secondPair.first = false;
        packet.getData(secondPair.second);

        defaultQueue.insert(std::make_pair(packet.getSequenceNumber(), secondPair));
        //defaultQueuedElements.push_back(packet.getSequenceNumber());
        std::cout << "Added a packet! " << "Size: " << defaultQueue.size() << std::endl;
    }
}

std::vector<uint32_t>* DynamicQueue::getAckQueuedElements() {
    return &ackQueuedElements;
}

std::vector<uint32_t>* DynamicQueue::getDefaultQueuedElements() {
    return &defaultQueuedElements;
}

