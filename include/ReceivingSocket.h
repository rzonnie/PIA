#ifndef RECEIVINGSOCKET_H
#define RECEIVINGSOCKET_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>

#include "BlockingQueue.h" 

class ReceivingSocket
{
    public:
        ReceivingSocket(std::string ip, int port, std::string group);
    protected:
    private:
        int get_receive_socket(std::string ip, uint16_t port, std::string group);
        int receivePacket(std::string ip, uint port, std::string group, BlockingQueue<std::string> &q);
        bool quit;
	void stopReceiving();
};

#endif // RECEIVINGSOCKET_H
