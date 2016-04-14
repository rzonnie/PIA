#ifndef ROUTINGTABLESTRUCT_H_
#define ROUTINGTABLESTRUCT_H_

#include <stdint.h>
#include <iostream>
#include <chrono>

struct RoutingTableStruct
{
    uint32_t to;
    int16_t distance;
    uint32_t via;
    std::chrono::time_point<std::chrono::system_clock> stamp; // timestamp
};

#endif /* ROUTINGTABLESTRUCT_H_ */
