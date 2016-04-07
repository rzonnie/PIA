#include "../include/RoutingTable.h"

using namespace std;

RoutingTable::RoutingTable(int ID) {
    setMyIdentifier(ID);
    uint8_t to = ID;
    uint8_t distance = 0;
    uint8_t via = ID;
    addRoutingTableStruct(makeStruct(to, via, distance));
}

vector<RoutingTableStruct> RoutingTable::getRoutingTable() {
    return routingTable;
}

void RoutingTable::addRoutingTableStruct(RoutingTableStruct Entry) {
    routingTable.push_back(Entry);
}

void RoutingTable::setMyIdentifier(int ID) {
    myIdentifier = ID;
}

RoutingTableStruct RoutingTable::makeStruct(uint8_t to, uint8_t via, uint8_t distance) {
    RoutingTableStruct NewEntry;
    NewEntry.to = to;
    NewEntry.via = via;
    NewEntry.distance = distance;
    return NewEntry;
}

void RoutingTable::updateRoutingTable(vector <RoutingTableStruct> NewRoutingTable) {
    int k = 0; //Solution to the accessing specific 
    bool newElement = false;
    for (auto i : NewRoutingTable) //Loop over all routing table entries
    {
        if (i.via != myIdentifier) //This checks if this entry is not measured from me as a point to prevent loops
        {
            for (auto j : routingTable) //Loop over all routing table entries to consider if you have the destination already
            {
                if (j.to == i.to) //Check if the destination is already in your list
                {
                    if (j.distance > i.distance + 1) //Is the distance smaller than at least the step to the node?
                    {
                        cout << "Ik kom hier 1x " << i.distance + 1 << endl;
                        routingTable.erase(routingTable.begin() + k - 1); //Use k instead of auto, otherwise .begin and.erase are not possible.
                        addRoutingTableStruct(makeStruct(i.to, NewRoutingTable[0].via, i.distance + 1));
                        printf("%u\n", j.distance);
                        printf("%u\n", j.via);
                    }
                    newElement = true;
                }
                k++; //Increase k to still be able to access the k'th element of the vector
            }
            if (!newElement) //If j looped over the full routing table I already had, and the destination was not found there:
            {
                addRoutingTableStruct(makeStruct(i.to, NewRoutingTable[0].via, i.distance + 1)); //Add it to my routing table
            }
        }
        newElement = false;
        k = 0;
    }
}

/*
void routingTable::printRoutingTable(){
        for (auto element : RoutingTable) {
                for (auto element2 : element) {
                        cout << "Temp" << element.to << endl;
                }
        }
}*/
