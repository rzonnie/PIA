// -*- C++ -*-
/* 
 * File:   main.
 * Author: remi
 *
 * Created on April 6, 2016, 10:42 AM
 */

#ifndef ROUTINGTABLE_
#define	ROUTINGTABLE_

#include <vector>
#include "RoutingTableStruct.h" 

using namespace std;

class RoutingTable {
private:
    uint8_t myIdentifier;
    vector<RoutingTableStruct> routingTable;
public:
    RoutingTable(int ID);
    vector<RoutingTableStruct> getRoutingTable();
    RoutingTableStruct makeStruct(uint8_t to, uint8_t via, uint8_t distance);
    void addRoutingTableStruct(RoutingTableStruct Entry);
    void setMyIdentifier(int ID);
    void updateRoutingTable(vector <RoutingTableStruct> NewRoutingTable);
};

#endif	/* ROUTINGTABLE_ */