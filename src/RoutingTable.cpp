#include "../include/RoutingTable.h"

using namespace std;

RoutingTable::RoutingTable() {
    pthread_mutex_init(&mutex_queue, NULL);
}

RoutingTable::RoutingTable(Settings* settings, uint32_t ID)
: settings(settings), myIdentifier(ID) {
    uint32_t to = ID;
    int16_t distance = 0;
    uint32_t via = ID;
    addRoutingTableStruct(makeStruct(to, via, distance));
}

vector<RoutingTableStruct>* RoutingTable::getRoutingTable() {
    return &routingTable;
}

vector<uint32_t> RoutingTable::getHosts() const {
    vector<uint32_t> temp = {};
    for (auto element : routingTable) {
        temp.push_back(element.to);
    }
    return temp;
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

RoutingTableStruct RoutingTable::makeStruct(uint32_t to, uint32_t via, int16_t distance) {
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
                    if (j.to != settings->getLocalIP()) {
                        if (i.distance == settings->getInfinite() && j.distance != settings->getInfinite()) {
                            pthread_mutex_lock(&mutex_queue);
                            routingTable.erase(routingTable.begin() + k); //Use k instead of auto, otherwise .begin and.erase are not possible.
                            RoutingTableStruct temp = makeStruct(i.to, newRoutingTable.getMyIdentifier(), settings->getInfinite());
                            pthread_mutex_unlock(&mutex_queue);
                            addRoutingTableStruct(temp);
                        } else if (j.distance >= i.distance + 1) //Is the distance smaller than at least the step to the node?
                        {
                            pthread_mutex_lock(&mutex_queue);
                            routingTable.erase(routingTable.begin() + k); //Use k instead of auto, otherwise .begin and.erase are not possible.
                            RoutingTableStruct temp = makeStruct(i.to, newRoutingTable.getMyIdentifier(), i.distance + 1);
                            pthread_mutex_unlock(&mutex_queue);
                            addRoutingTableStruct(temp);
                        }
                    }
                    newElement = false;
                }
                k++; //Increase k to still be able to access the k'th element of the vector
            }
            if (newElement && i.distance != settings->getInfinite()) //If j looped over the full routing table I already had, and the destination was not found there:
            {
                addRoutingTableStruct(makeStruct(i.to, newRoutingTable.getMyIdentifier(), i.distance + 1)); //Add it to my routing table
            }
        }
        newElement = true;
        k = 0;
    }
}

std::vector<uint32_t> RoutingTable::tagFallouts() {
    std::vector<uint32_t> fallOuts = {};
    std::chrono::time_point<std::chrono::system_clock> now;
    now = std::chrono::system_clock::now();

    for (size_t i = 0; i < routingTable.size(); i++) {
        std::chrono::duration<double> timeElapsed = now - routingTable[i].stamp;

        // When was the last update?
        if (routingTable[i].to != myIdentifier) {
            pthread_mutex_lock(&mutex_queue);
            if (timeElapsed.count() > 7 && routingTable[i].distance == -1) {
                fallOuts.push_back(routingTable[i].to);
                routingTable.erase(routingTable.begin() + i);
                std::cout << "Erased an element" << " for " << printIP(routingTable[i].to) << std::endl;
            } else if (timeElapsed.count() > 4) {
                //std::cout << "Time elapsed: " << timeElapsed.count() << " for " << printIP(routingTable[i].to) << std::endl;
                routingTable[i].distance = settings->getInfinite();
            }
            pthread_mutex_unlock(&mutex_queue);
        }
    }

    return fallOuts;
}

void RoutingTable::printRoutingTable() const {
    std::chrono::time_point<std::chrono::system_clock> now;
    now = std::chrono::system_clock::now();

    printf("\n\n| TO \t\t\t | DIS \t\t\t | VIA \t\t\t | STAMP \t |\n");
    printf("------------------------------------------------------------------------------------------\n");
    for (auto element : routingTable) {
        std::chrono::duration<double> timeElapsed = now - element.stamp;
        std::string to = printIP(element.to);
        std::string via = printIP(element.via);
        printf("| %s \t\t| %i \t\t\t | %s \t | %f \t |\n", to.c_str(), element.distance, via.c_str(), timeElapsed.count());
    }
}

uint32_t RoutingTable::getNextHop(uint32_t destinationAddress) {
    vector<RoutingTableStruct>* table = this->getRoutingTable();
    for (auto element : *table) {
        if (element.to == destinationAddress) {
            //std::cout << "NEXT HOP: " << printIP(element.via) << std::endl;
            //std::cout << "TARGET\t: " << printIP(destinationAddress) << std::endl;
            return element.via;
        }
    }
    std::cout << "ERROR: NEXT HOP NOT FOUND" << std::endl;
    return 0;
}
