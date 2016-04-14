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
#include <chrono>
#include <algorithm>
#include "functions.h"
#include <thread>

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
    
    /**
     * Necessary for thread locking
     */
    pthread_mutex_t mutex_queue;
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
    RoutingTableStruct makeStruct(uint32_t to, uint32_t via, int16_t distance);
    std::vector<uint32_t> tagFallouts();
    
    void addRoutingTableStruct(RoutingTableStruct Entry);
    void setMyIdentifier(int ID);
    int getMyIdentifier() const;
    void updateRoutingTable(RoutingTable &newRoutingTable);
    void printRoutingTable() const;
    uint32_t getNextHop(uint32_t destinationAddress);
    vector<uint32_t> getHosts() const;
};

#endif /* ROUTINGTABLE_ */
