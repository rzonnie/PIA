/* 
 * File:   sendSocket.h
 * Author: Olaf van der Meer, Guido Kuijper, Bart van der Scheer and Remi Jonkman
 * Group 9
 * 
 * Created on April 7, 2016, 2:33 PM
 */

#ifndef SENDSOCKET_H
#define SENDSOCKET_H

#include <string>
#include <cstring>
#include <stdexcept>
#include <iostream>

#include "Socket.h"
#include "PIA.h"

class SendSocket : public Socket {
public:
    SendSocket(Settings* settings, DynamicQueue* dynamicQueue);
    virtual ~SendSocket();
    
    void run() override;
    void init() override;

private:
    /**
     * Send an arbitrary packet
     * @param packet PIA
     */
    void sendPacket(PIA &packet);
};

#endif /* SENDSOCKET_H */

