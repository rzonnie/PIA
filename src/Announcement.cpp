#include "../include/Announcement.h"

Announcement::Announcement(Settings* settings, DynamicQueue* sendQueue, RoutingTable* routingTable)
: ThreadRunner(settings), sendQueue(sendQueue), routingTable(routingTable) {
    // Empty
}

void Announcement::run() {
    while (true) {
        std::cout << "Announce" << std::endl;
        std::string message = stringify();
        PIA packet(settings->getMulticastGroup(), 5000, 5000, false, true, message);
        sendQueue->push_back(packet);
        sleep(2);
    }
}

std::string Announcement::stringify() {
    std::string strRoutingTable;

    for (auto i : routingTable->getRoutingTable()) {
        strRoutingTable.append(std::to_string(i.to));
        strRoutingTable.append(std::to_string(i.distance));
        strRoutingTable.append(std::to_string(i.via));
        strRoutingTable.append(std::to_string(i.from));

    }
    
    std::cout << strRoutingTable << std::endl;
    
    return strRoutingTable;
}
