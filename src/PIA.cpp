/*
 * PIA.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: bart
 */

#include "../include/PIA.h"

PIA::PIA() {
    // TODO Auto-generated constructor stub

}

PIA::~PIA() {
    // TODO Auto-generated destructor stub
}

void PIA::setAcknowledgementNumber(uint32_t acknowledgementNumber) {
    AcknowledgementNumber = acknowledgementNumber;
}

void PIA::setDestinationAddress(uint32_t destinationAddress) {
    //inet_addr(localIP.c_str());
    this->destinationAddress = destinationAddress;
}

void PIA::setHeaderLength(uint16_t headerLength) {
    this->headerLength = headerLength;
}

//set flags

void PIA::setNta(bool nta) {

}

void PIA::setAck(bool ack) {

}

void PIA::setSequenceNumber(uint32_t sequenceNumber) {
    this->sequenceNumber = sequenceNumber;
}

std::string PIA::getData() {

    //clear the data string
    PIAdata.clear();
    PIAdata = std::to_string(destinationAddress);
    //(std::string)destinationAddress + (std::string)sequenceNumber + (std::string)AcknowledgementNumber + (std::string)NTA + (std::string)ACK;


    std::cout << sizeof (PIAdata) << std::endl;

    return PIAdata;
}
