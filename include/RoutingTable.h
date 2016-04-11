// -*- C++ -*-
/* 
 * File:   main.
 * Author: remi
 *
 * Created on April 6, 2016, 10:42 AM
 */

#ifndef ROUTINGTABLE_
#define ROUTINGTABLE_

#include <vector>
#include "RoutingTableStruct.h" 
#include "Settings.h"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;

template<class Archive>
void serialize(Archive & ar, RoutingTableStruct & r, const unsigned int version) {
    ar & r.to;
    ar & r.distance;
    ar & r.via;
}

class RoutingTable {
private:
    uint32_t myIdentifier;
    Settings* settings;
    vector<RoutingTableStruct> routingTable = {};
public:
    // Give boost access to the member functions and variables
    friend class boost::serialization::access;

    template<class Archive> void serialize(Archive & ar, const unsigned int version) {
        ar & myIdentifier;
        ar & routingTable;
    }

    RoutingTable();
    RoutingTable(Settings* settings, uint32_t ID);
    vector<RoutingTableStruct>* getRoutingTable();
    RoutingTableStruct makeStruct(uint32_t to, uint32_t via, uint32_t distance);
    void addRoutingTableStruct(RoutingTableStruct Entry);
    void setMyIdentifier(int ID);
    int getMyIdentifier() const;
    void updateRoutingTable(RoutingTable &newRoutingTable);
    void printRoutingTable() const;
};

#endif /* ROUTINGTABLE_ */