#include "../include/Announcement.h"


Announcement::Announcement(std::string ip, int port, std::string group, std::vector<struct RoutingTableStruct> routingTable)
{
    quit = false;
    constantAnnounce(ip, port, group, routingTable); //go immediately into the loop
}

void Announcement::constantAnnounce(std::string ip, int port, std::string group, std::vector<struct RoutingTableStruct> routingTable)
{
    int sock = -1;
    try {
        /**
         * Create a new datagram socket
         */
        if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
            throw std::runtime_error("Socket creation failed");

        /**
         * Enable/Disable loopback. (loop = 0 is disabled, loop =1 is enabled)
         * This allows you to receive multicast packets you yourself have send.
         * Obviously enabling this is not really useful for anything but testing
         */
        char loop = 0;
        if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, (char *) &loop, sizeof (loop)) < 0)
            throw std::runtime_error("Failed to disable loopback");

        /**
         * Set the interface to send multicast packets on.
         * This should be our own IP address
         */
        struct in_addr local = {0};
        local.s_addr = inet_addr(ip.c_str());
        if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, (char *) &local, sizeof (local)) < 0)
            throw std::runtime_error("Local interface failed");

        /**
         * Fill in the sockaddr_in to specify the destination of datagrams
         * In this case this is simply a port and multicast group address
         */
        struct sockaddr_in multicastSender = {0};
        multicastSender.sin_family = AF_INET;
        multicastSender.sin_addr.s_addr = inet_addr(group.c_str());
        multicastSender.sin_port = htons(port);

        //send a packet every 5 seconds
        while (!quit) {
            std::string message = stringify(routingTable);
            if (sendto(sock, message.c_str(), message.size(), 0, (struct sockaddr*) &multicastSender, sizeof (struct sockaddr_in)) < 0) //sent a UDP packet containing our example data
                perror("Sendto failed");
            printf("Announcement of size %d sent!\n", (int) message.size());
            sleep(1);
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    if (sock != -1)
        close(sock);
}

void Announcement::quitAnnounce()
{
    quit = true;
}

std::string stringify (std::vector<struct RoutingTableStruct> routingTableIn)
{
    std::string strRoutingTable;

    for (auto i:routingTableIn)
    {
        strRoutingTable.append(std::to_string(i.to));
        strRoutingTable.append(std::to_string(i.distance));
        strRoutingTable.append(std::to_string(i.via));
        strRoutingTable.append(std::to_string(i.from));

    }
    return strRoutingTable;
}
