#ifndef RECEIVINGSOCKET_H
#define RECEIVINGSOCKET_H

#include "BlockingQueue.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>

class ReceivingSocket {
public:
    ReceivingSocket(std::string ip, int port, std::string group);
    bool isStopReceiving() const;
    int receivePacket(std::string ip, uint port, std::string group, BlockingQueue<std::string> &q);
    
private:
    int get_receive_socket(std::string ip, uint16_t port, std::string group);
    
    bool stopReceiving;
    int retsock;
};

#endif // RECEIVINGSOCKET_H
