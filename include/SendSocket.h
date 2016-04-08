/* 
 * File:   sendSocket.h
 * Author: Olaf van der Meer, Guido Kuijper, Bart van der Scheer and Remi Jonkman
 * Group 9
 * 
 * Created on April 7, 2016, 2:33 PM
 */

#ifndef SENDSOCKET_H
#define SENDSOCKET_H

#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "Settings.h"
#include "PIA.h"
#include "DynamicQueue.h"

class SendSocket {
public:
    SendSocket(Settings* settings, DynamicQueue* dynamicQueue);
    virtual ~SendSocket();
    
    void sendPacket(PIA &packet);
    void run();
private:
    Settings *settings;
    DynamicQueue* dynamicQueue;
    int sock = -1;
    bool quit = false;
};

#endif /* SENDSOCKET_H */

