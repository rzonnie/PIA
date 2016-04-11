#ifndef ROUTINGTABLESTRUCT_H_
#define ROUTINGTABLESTRUCT_H_

#include <stdint.h>
#include <iostream>

struct RoutingTableStruct
{
    uint32_t to;
    uint8_t distance;
    uint32_t via;
};

#endif /* ROUTINGTABLESTRUCT_H_ */
