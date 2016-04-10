#ifndef RECEIVINGSOCKET_H
#define RECEIVINGSOCKET_H

/*
#include "BlockingQueue.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
*/

#include <string>
#include <cstring>
#include <stdexcept>
#include <iostream>

#include "Socket.h"
#include "PIA.h"
#include "Settings.h"

class ReceivingSocket : public Socket {
public:
    ReceivingSocket(Settings* settings, DynamicQueue* receivingQueue);
    void run() override;

private:
    void init() override;
    void receivePacket();
};

#endif // RECEIVINGSOCKET_H
