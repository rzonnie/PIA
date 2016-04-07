#ifndef ROUTINGTABLESTRUCT_H_
#define ROUTINGTABLESTRUCT_H_

#include <stdint.h>
#include <iostream>

struct RoutingTableStruct
{
    uint8_t to;
    uint8_t distance;
    uint8_t via;
    uint8_t from;
};

#endif /* ROUTINGTABLESTRUCT_H_ */
