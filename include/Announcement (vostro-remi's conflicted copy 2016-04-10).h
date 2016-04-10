#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include "RoutingTableStruct.h"

#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <vector>

class Announcement
{
    public:
        Announcement(std::string ip, int port, std::string group, std::vector<struct RoutingTableStruct> routingTable);
    protected:
        bool quit;
        void constantAnnounce(std::string ip, int port, std::string group, std::vector<struct RoutingTableStruct> routingTable);
        void quitAnnounce();
        std::string stringify (std::vector<struct RoutingTableStruct> routingTableIn);

};

#endif // ANNOUNCEMENT_H
