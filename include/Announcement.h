#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include "RoutingTableStruct.h"
#include "DynamicQueue.h"
#include "Settings.h"
#include "ThreadRunner.h"
#include "RoutingTable.h"

#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <vector>

class Announcement : public ThreadRunner {
public:
    Announcement(Settings* settings, DynamicQueue* sendQueue, RoutingTable* routingTable);
    void run() override;

protected:
    RoutingTable* routingTable;
    DynamicQueue* sendQueue;
    std::string stringify();
};

#endif // ANNOUNCEMENT_H
