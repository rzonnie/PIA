/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sendSocket.cpp
 * Author: remi
 * 
 * Created on April 7, 2016, 2:33 PM
 */

#include "SendSocket.h"
#include "Settings.h"

SendSocket::SendSocket(Settings* settings) {
    this->settings = settings;
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
        local.s_addr = settings->getLocalIP();
        if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, (char *) &local, sizeof (local)) < 0)
            throw std::runtime_error("Local interface failed");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        throw e;
    }
}

SendSocket::~SendSocket() {
    if (sock != -1)
        close(sock);
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

    char buffer[1500] = {};

    //read a packet
    packet.getData(buffer);

    for (uint cnt = 0; cnt < packet.size(); ++cnt) {
        std::bitset<8> henk(buffer[cnt]);
        std::cout << "Byte " << cnt << " " << henk << " " << buffer[cnt] << std::endl;
    }

    //send a packet every 5 seconds
    if (sendto(sock, buffer, settings->getMTU(), 0, (struct sockaddr*) &multicastSender, sizeof (struct sockaddr_in)) < 0) //sent a UDP packet containing our example data
        perror("Sendto failed");
    printf("Packet of size %d sent!\n", (int) packet.size());
}



