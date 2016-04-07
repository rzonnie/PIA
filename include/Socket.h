#ifndef SOCKET_H
#define SOCKET_H

#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <sys/types.h>
#include <stdlib.h>

class Socket
{
    public:
        Socket(bool sendingSocket, std::string ip, int port, std::string group);
        ~Socket();
    protected:
        void makeSendingSocket(std::string ip, int port, std::string group);
        void sendPacket(std::string message);
        void makeReceivingSocket(std::string ip, int port, std::string group);
        int receivePacket(std::string ip, int port, std::string group, BlockingQueue<std::string> &q)
};

#endif // SOCKET_H
