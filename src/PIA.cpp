/*
 * PIA.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: bart
 */

#include "../include/PIA.h"
#include <bitset>

PIA::PIA() {
    // empty constructor ^^
}

PIA::PIA(uint32_t destinationAddress, uint32_t sequenceNumber, uint32_t acknowledgementNumber,bool ACK, bool NTA) {
    //constructor with arguments
	this->destinationAddress = destinationAddress;
	this->sequenceNumber = sequenceNumber;
	this->acknowledgementNumber = acknowledgementNumber;
	setAck(ACK);
	setNta(NTA);
}

PIA::PIA(uint32_t destinationAddress, uint32_t sequenceNumber, uint32_t acknowledgementNumber,bool ACK, bool NTA, std::string payload) {
    //constructor with arguments (and payload)
	this->destinationAddress = destinationAddress;
	this->sequenceNumber = sequenceNumber;
	this->acknowledgementNumber = acknowledgementNumber;
	setPayload(payload);
	setAck(ACK);
	setNta(NTA);
}

PIA::~PIA() {
    //destructor
}

void PIA::setAcknowledgementNumber(uint32_t acknowledgementNumber) {
    this->acknowledgementNumber = acknowledgementNumber;
}

uint32_t PIA::getAcknowledgementNumber() const {
    return this->acknowledgementNumber;
}

void PIA::setDestinationAddress(uint32_t destinationAddress) {
    //inet_addr(localIP.c_str());
    this->destinationAddress = destinationAddress;
}

//set flags

void PIA::setNta(bool nta) {
    if (nta)
        flagsAndHeader |= (1 << 31);
    else
        flagsAndHeader &= ~(1 << 31);
}

void PIA::setAck(bool ack) {
    if (ack)
        flagsAndHeader |= (1 << 30);
    else
        flagsAndHeader &= ~(1 << 30);
}

bool PIA::isAck() const {
    return (flagsAndHeader >> 30 & 1);
}

void PIA::setSequenceNumber(uint32_t sequenceNumber) {
    this->sequenceNumber = sequenceNumber;
}

uint32_t PIA::getSequenceNumber() const {
    return sequenceNumber;
}

void PIA::setPayload(std::string payload) {
    this->payload = payload;
}

void PIA::readData(char* buffer[]) {

}

void PIA::getData(char buffer[]) {
    //Complete packet

    buffer[0] = (destinationAddress >> 24) & 0xff;
    buffer[1] = (destinationAddress >> 16) & 0xff;
    buffer[2] = (destinationAddress >> 8) & 0xff;
    buffer[3] = destinationAddress & 0xff;

    buffer[4] = (sequenceNumber >> 24) & 0xff;
    buffer[5] = (sequenceNumber >> 16) & 0xff;
    buffer[6] = (sequenceNumber >> 8) & 0xff;
    buffer[7] = sequenceNumber & 0xff;

    buffer[8] = (acknowledgementNumber >> 24) & 0xff;
    buffer[9] = (acknowledgementNumber >> 16) & 0xff;
    buffer[10] = (acknowledgementNumber >> 8) & 0xff;
    buffer[11] = acknowledgementNumber & 0xff;

    buffer[12] = (flagsAndHeader >> 24) & 0xff;
    buffer[13] = (flagsAndHeader >> 16) & 0xff;
    buffer[14] = (flagsAndHeader >> 8) & 0xff;
    buffer[15] = flagsAndHeader & 0xff;

    // Put the payload inside the packet
    strncpy(buffer + headerLength, payload.c_str(), maxSize);
}

size_t PIA::size() const {
    std::cout << payload.size() + headerLength << std::endl;
    return payload.size() + headerLength;
}

void PIA::printPacket(){
    char buffer[1400] = {};
    this->getData(buffer);

	uint max = this->size();
	for (uint cnt = 0; cnt < max; ++cnt) {
		std::bitset<8> henk(buffer[cnt]);
		std::cout << "Byte " << cnt << " " << henk << std::endl;
    }
}
