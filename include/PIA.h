/*
 * PIA.h
 *
 *  Created on: Apr 6, 2016
 *      Author: bart
 */

#include <string>
#include <bitset>
#include <iostream>

#ifndef SRC_PIA_H_
#define SRC_PIA_H_

class PIA {
public:
    PIA();
    virtual ~PIA();

    //returns the complete PIA protocol data
    std::string getData();

    //set properties
    void setAck(bool ack);
    void setAcknowledgementNumber(uint32_t acknowledgementNumber = {
        0x0000000000000000
    });
    void setDestinationAddress(uint32_t destinationAddress = {
        0x0000000000000000
    });
    void setHeaderLength(uint16_t headerLength = {0x00000000});
    void setNta(bool nta);
    void setSequenceNumber(uint32_t sequenceNumber = {0x0000000000000000});

private:
    //Complete packet
    std::string PIAdata;

    //Packet contents
    uint destinationAddress = 0; //0 - 31
    uint sequenceNumber = 0; //32 -63
    uint AcknowledgementNumber = 0; //64 - 95
    bool NTA; // 96
    bool ACK; // 97
    // 98 - 111 Reserved
    uint16_t headerLength = 0; //112-127
};

#endif /* SRC_PIA_H_ */
