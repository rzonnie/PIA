/*
 * PIA.h
 *
 *  Created on: Apr 6, 2016
 *      Author: bart
 */

#include <string>
#include <bitset>
#include <iostream>
#include <string>
#include <cstring>

#ifndef SRC_PIA_H_
#define SRC_PIA_H_

class PIA {
public:
    PIA();
    virtual ~PIA();

    //returns the complete PIA protocol data
    std::string getData();

    //set properties
    void setDestinationAddress(uint32_t destinationAddress);
    void setSequenceNumber(uint32_t sequenceNumber);
    void setAcknowledgementNumber(uint32_t acknowledgementNumber);
    void setHeaderLength(uint16_t headerLength = {0x00000000});
    
    void setAck(bool ack);
    void setNta(bool nta);


private:
    //Packet contents
    uint32_t destinationAddress = 0; //0 - 31
    uint32_t sequenceNumber = 0; //32 -63
    uint32_t acknowledgementNumber = 0; //64 - 95
    uint32_t flagsAndHeader = 0; // 96 - 127
    std::string payload = "empty shizzle"; // 128 - ...
};

#endif /* SRC_PIA_H_ */
