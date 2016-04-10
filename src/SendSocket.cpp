/* 
 * File:   sendSocket.cpp
 * Author: remi
 * Group: 9
 * Created on April 7, 2016, 2:33 PM
 */

#include "../include/SendSocket.h"

SendSocket::SendSocket(Settings* settings, DynamicQueue* dynamicQueue)
: Socket(settings, dynamicQueue) {
    init();
}

void SendSocket::init() {
    try {
        /**
         * Enable/Disable loopback. (loop = 0 is disabled, loop =1 is enabled)
         * This allows you to receive multicast packets you yourself have send.
         * Obviously enabling this is not really useful for anything but testing
         */
        char loop = 0;
        if (setsockopt(sockID, IPPROTO_IP, IP_MULTICAST_LOOP, (char *) &loop, sizeof (loop)) < 0)
            throw std::runtime_error("Failed to disable loopback");

        /**
         * Set the interface to send multicast packets on.
         * This should be our own IP address
         */
        struct in_addr local = {0};
        local.s_addr = settings->getLocalIP();
        if (setsockopt(sockID, IPPROTO_IP, IP_MULTICAST_IF, (char *) &local, sizeof (local)) < 0)
            throw std::runtime_error("Local interface failed");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        throw e;
    }
}

SendSocket::~SendSocket() {
}

void SendSocket::run() {
    while (true) {
        sleep(1);
        PIA packet = queue->retrievePacket();
        if (packet.getDestinationAddress() > 0)
            sendPacket(packet);
    }
}

void SendSocket::sendPacket(PIA &packet) {
    /**
     * Fill in the sockaddr_in to specify the destination of datagrams
     * In this case this is simply a port and multicast group address
     */
    struct sockaddr_in multicastSender = {0};
    multicastSender.sin_family = AF_INET;
    multicastSender.sin_addr.s_addr = settings->getMulticastGroup();
    multicastSender.sin_port = htons(settings->getPort());

    // Create a buffer for the packet
    char buffer[1500] = {};

    //read a packet
    packet.getData(buffer);

    // send the actual packet
    if (sendto(sockID, buffer, packet.size(), 0, (struct sockaddr*) &multicastSender, sizeof (struct sockaddr_in)) < 0) //sent a UDP packet containing our example data
        perror("Sendto failed");
    //printf("Packet of size %d sent!\n", (int) packet.size());
}



