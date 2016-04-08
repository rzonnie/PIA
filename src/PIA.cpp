/*
 * PIA.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: bart
 */

#include "../include/PIA.h"

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

void PIA::readData(char buffer[]) {

	//read the packet header
	destinationAddress		= ((buffer[0]&0xff)) | ((buffer[1]&0xff)<<8) | ((buffer[2]&0xff)<<16) | ((buffer[3]&0xff)<<24);
	sequenceNumber			= ((buffer[7]&0xff)) | ((buffer[6]&0xff)<<8) | ((buffer[5]&0xff)<<16) | ((buffer[4]&0xff)<<24);
	acknowledgementNumber	= ((buffer[11]&0xff)) | ((buffer[10]&0xff)<<8) | ((buffer[9]&0xff)<<16) | ((buffer[8]&0xff)<<24);
	flagsAndHeader			= ((buffer[15]&0xff)) | ((buffer[14]&0xff)<<8) | ((buffer[13]&0xff)<<16) | ((buffer[12]&0xff)<<24);

	//read the payload
	payload.clear();
    uint i = headerLength;
    while(i<maxSize+headerLength){
    	//std::cout<<buffer[i]<<"|";
    	payload.push_back(buffer[i]);
    	i++;
    }
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
    std::cout <<"Packet size: "<< payload.size() + headerLength << std::endl;
    return payload.size() + headerLength;
}

void PIA::printPacket(bool format){
    //Print readable data
	if(format){
    	std::cout<<"\n*Destination Address\t: ";
    	char ipAddr[16];
    	snprintf(ipAddr,sizeof ipAddr,"%u.%u.%u.%u" ,(destinationAddress & 0xff000000) >> 24
    												,(destinationAddress & 0x00ff0000) >> 16
    												,(destinationAddress & 0x0000ff00) >> 8
    												,(destinationAddress & 0x000000ff));
        std::cout<<ipAddr;
        std::cout<<"\n*Sequence Number\t: "<<sequenceNumber
        		 <<"\n*Acknowledgement Number\t: "<<acknowledgementNumber
    			 <<"\n*Flags & Header\t\t: "<<std::bitset<32>(flagsAndHeader)
    			 <<"\n*Payload ("<<strlen(payload.c_str())<<" bytes)\t: "<<payload
    			 <<std::endl;
    }
    //Print raw bytes
    else{
		char buffer[1488] = {};
		this->getData(buffer);

		uint max = this->size();
		std::cout << "-----Header----- " <<std::endl;
		if(max>maxSize) max=maxSize+headerLength;
		for (uint cnt = 0; cnt < max; ++cnt) {
			std::bitset<8> henk(buffer[cnt]);
			if(cnt == headerLength) std::cout << "-----Payload----- " <<std::endl;
			std::cout << "Byte " << cnt << " " << henk << std::endl;
		}
		std::cout<<std::endl;
    }
}

uint32_t PIA::getDestinationAddress() const{
	return destinationAddress;
}

std::string PIA::getPayload() const{
	return payload;
}
