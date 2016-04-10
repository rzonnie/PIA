#include "../include/Announcement.h"
#include <sstream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>

Announcement::Announcement(Settings* settings, DynamicQueue* sendQueue, RoutingTable* routingTable)
: ThreadRunner(settings), sendQueue(sendQueue), routingTable(routingTable) {
    // Empty
}

void Announcement::run() {
    while (true) {
        //std::cout << "Announce" << std::endl;
        std::string message = stringify();
        PIA packet(settings->getMulticastGroup(), 5000, 5000, false, true, message);
        sendQueue->push_back(packet);
        sleep(2);
    }
}

std::string Announcement::stringify() {
    std::ostringstream archive_stream;
    boost::archive::text_oarchive archive(archive_stream);
    archive << *routingTable;

    return archive_stream.str();
}
