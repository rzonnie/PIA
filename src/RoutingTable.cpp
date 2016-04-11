#include "../include/RoutingTable.h"
#include "../include/functions.h"

using namespace std;

RoutingTable::RoutingTable() {

}

RoutingTable::RoutingTable(Settings* settings, uint32_t ID)
: settings(settings), myIdentifier(ID) {
    uint32_t to = ID;
    uint8_t distance = 0;
    uint32_t via = ID;
    addRoutingTableStruct(makeStruct(to, via, distance));
}

vector<RoutingTableStruct>* RoutingTable::getRoutingTable() {
    return &routingTable;
}

void RoutingTable::addRoutingTableStruct(RoutingTableStruct Entry) {
    routingTable.push_back(Entry);
}

void RoutingTable::setMyIdentifier(int ID) {
    myIdentifier = ID;
}

int RoutingTable::getMyIdentifier() const {
    return myIdentifier;
}

RoutingTableStruct RoutingTable::makeStruct(uint32_t to, uint32_t via, uint8_t distance) {
    RoutingTableStruct NewEntry;
    NewEntry.to = to;
    NewEntry.via = via;
    NewEntry.distance = distance;
    NewEntry.stamp = std::chrono::system_clock::now();
    return NewEntry;
}

void RoutingTable::updateRoutingTable(RoutingTable &newRoutingTable) {
    int k = 0; //Solution to the accessing specific 
    bool newElement = true;

    for (auto i : *(newRoutingTable.getRoutingTable())) //Loop over all routing table entries
    {
        if (i.via != myIdentifier) //This checks if this entry is not measured from me as a point to prevent loops
        {
            for (auto j : routingTable) //Loop over all routing table entries to consider if you have the destination already
            {
                if (j.to == i.to) //Check if the destination is already in your list
                {
                    if (j.distance >= i.distance + 1) //Is the distance smaller than at least the step to the node?
                    {
                        cout << "Ik kom hier 1x " << i.distance + 1 << endl;
                        routingTable.erase(routingTable.begin() + k); //Use k instead of auto, otherwise .begin and.erase are not possible.
                        RoutingTableStruct temp = makeStruct(i.to, newRoutingTable.getMyIdentifier(), i.distance + 1);
                        //routingTable[k - 1] = temp;
                        addRoutingTableStruct(temp);
                        printf("%u\n", j.distance);
                        //printf("%u\n", j.via);
                    }
                    newElement = false;
                }
                k++; //Increase k to still be able to access the k'th element of the vector
            }
            if (newElement) //If j looped over the full routing table I already had, and the destination was not found there:
            {
                std::cout << "New Entry" << std::endl;
                addRoutingTableStruct(makeStruct(i.to, newRoutingTable.getMyIdentifier(), i.distance + 1)); //Add it to my routing table
            }
        }
        newElement = true;
        k = 0;
    }
}

void RoutingTable::tagFallouts() {
    std::chrono::time_point<std::chrono::system_clock> now;
    now = std::chrono::system_clock::now();

    for (size_t i = 0; i < routingTable.size(); i++) {
        std::chrono::duration<double> timeElapsed = now - routingTable[i].stamp;

        // When was the last update?
        if (routingTable[i].to != myIdentifier) {
            if (timeElapsed.count() > 12 && routingTable[i].distance == 0) {
                //auto it = std::find(routingTable.begin(), routingTable.end(), element);
                routingTable.erase(routingTable.begin() + i);
                std::cout << "Erased an element" << " for " << printIP(routingTable[i].to) << std::endl;
                printRoutingTable();
            } else if (timeElapsed.count() > 8) {
                //std::cout << "Time elapsed: " << timeElapsed.count() << " for " << printIP(routingTable[i].to) << std::endl;
                routingTable[i].distance = 0;
            }
        }
    }
}

void RoutingTable::printRoutingTable() const {
    printf("| TO \t\t\t | DIS \t\t\t | VIA \t\t\t |\n");
    printf("----------------------------------------------------------------------\n");
    for (auto element : routingTable) {
        std::string to = printIP(element.to);
        std::string via = printIP(element.via);
        printf("| %s \t\t| %u \t\t\t | %s \t |\n", to.c_str(), element.distance, via.c_str());
    }
}