#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H
#include "RoutingTableStruct.h"

class Announcement
{
    public:
        Announcement(struct RoutingTableStruct RoutingTable);
    protected:
        bool quit;
        void constantAnnounce(struct RoutingTableStruct RoutingTable);
        void quitAnnounce();
};

#endif // ANNOUNCEMENT_H
