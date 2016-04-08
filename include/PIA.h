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
#include <vector>

#ifndef SRC_PIA_H_
#define SRC_PIA_H_

class PIA {
public:
    PIA();
    PIA(uint32_t destinationAddress, uint32_t sequenceNumber, uint32_t acknowledgementNumber, bool ACK, bool NTA);
    PIA(uint32_t destinationAddress, uint32_t sequenceNumber, uint32_t acknowledgementNumber, bool ACK, bool NTA, std::string payload);
    virtual ~PIA();

    //returns the complete PIA protocol data
    void getData(char buffer[]);
    void readData(char* buffer[]);

    //set properties
    void setDestinationAddress(uint32_t destinationAddress);
    void setSequenceNumber(uint32_t sequenceNumber);
    void setAcknowledgementNumber(uint32_t acknowledgementNumber);
    void setPayload(std::string payload);
    
    void setAck(bool ack);
    void setNta(bool nta);

    void printPacket();
    size_t size() const;

private:
    //Packet contents
    uint32_t destinationAddress = 0; //0 - 31
    uint32_t sequenceNumber = 0; //32 -63
    uint32_t acknowledgementNumber = 0; //64 - 95
    uint32_t flagsAndHeader = 0; // 96 - 127
    std::string payload = ""; // 128 - ...

    const uint headerLength = 16;
    const uint maxSize = 1472;
};

#endif /* SRC_PIA_H_ */
