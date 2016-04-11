#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include "DynamicQueue.h"
#include "Settings.h"
#include "ThreadRunner.h"
#include "RoutingTable.h"

#include <string>
#include <iostream>
#include <vector>

// Required for serialization
#include <sstream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>

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
