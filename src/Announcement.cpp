#include "../includes/Announcement.h"

Announcement::Announcement(struct RoutingTableStruct RoutingTable)
{
    quit = false;
    constantAnnounce(RoutingTable); //go immediately into the loop
}

void constantAnnounce(struct RoutingTableStruct RoutingTable)
{
    Socket AnnouncementSocket(1);
    while(!quit)
    {
        AnnouncementSocket.sendPacket("hoi, test-message");
        sleep(1);
    }
}

void quitAnnounce()
{
    quit = true;
    AnnouncementSocket.~Socket;
}
