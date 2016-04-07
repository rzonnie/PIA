#include "../includes/Announcement.h"

Announcement::Announcement(struct RoutingTableStruct RoutingTable)
{
    quit = false;
    constantAnnounce(RoutingTable); //go immediately into the loop
}

void constantAnnounce(struct RoutingTableStruct RoutingTable)
{
    while(!quit)
    {
        sendPacket      // TO BE ADDED
        sleep(1);
    }
}

void quitAnnounce()
{
    quit = true;
}
