#ifndef RECEIVINGSOCKET_H
#define RECEIVINGSOCKET_H

#include <string>
#include <cstring>
#include <stdexcept>
#include <iostream>

#include "Socket.h"
#include "PIA.h"
#include "Settings.h"
#include "RoutingTable.h"

class ReceivingSocket : public Socket {
public:
    ReceivingSocket(Settings* settings, DynamicQueue* receivingQueue);
    void run() override;

private:
    void init() override;
    void receivePacket();
};

#endif // RECEIVINGSOCKET_H
