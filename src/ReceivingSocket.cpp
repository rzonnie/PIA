#include "../include/ReceivingSocket.h"

ReceivingSocket::ReceivingSocket(Settings *settings, DynamicQueue* receivingQueue)
: Socket(settings, receivingQueue) {
    init();
}

void ReceivingSocket::init() {
    /**
     * Setting the reuse var to 1 so multiple programs can read from this port
     * This is only useful if you want multiple clients to be able to listen on this port, for example when testing your application locally
     * It only really makes sense to use it this way with multicast traffic
     */
    int reuse = 0;
    if (setsockopt(sockID, SOL_SOCKET, SO_REUSEADDR, (char *) &reuse, sizeof (reuse)) < 0)
        throw std::runtime_error("Failed to set SO_REUSEADDR!");

    /**
     * Bind the socket to all addresses on our system and a specific port
     */
    struct sockaddr_in local = {0};
    memset((char *) &local, 0, sizeof (local));
    local.sin_family = AF_INET;
    local.sin_port = htons(settings->getPort());
    local.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockID, (struct sockaddr*) &local, sizeof (local)))
        throw std::runtime_error("Failed to bind socket!");

    /**
     * Join a multicast group
     * If we do not do this we wont receive or accept any multicast packets on this socket
     */
    struct ip_mreq group_req; //struct for multicast group requests
    group_req.imr_multiaddr.s_addr = settings->getMulticastGroup(); //the multicast address to join
    group_req.imr_interface.s_addr = settings->getLocalIP(); //the address of the interface to perform the join on (our IP address)
    if (setsockopt(sockID, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *) &group_req, sizeof (group_req)) < 0)
        throw std::runtime_error("Failed to join multicast group!");
}

void ReceivingSocket::run() {
    while (!quit) {
        usleep(50);
        receivePacket();
    }
}

void ReceivingSocket::receivePacket() {
    try {
        // prepare a structure to put peer data into
        struct sockaddr_in peer_address;
        socklen_t peer_address_len;
        peer_address_len = sizeof (struct sockaddr_storage);

        // allocate memory to put the received data into
        char data[1500] = {};
        int len;
        len = 0;

        // Receive packet and put its contents in data, recvfrom will block until a packet for this socket has been received
        len = recvfrom(sockID, data, sizeof (data), 0, (struct sockaddr *) &peer_address, &peer_address_len);
        //std::cout << "Packet Received: " << data << " data length: " << len << std::endl;
        //if (len > 0) {
        //    q.push(std::string(data, len));
        //}

        PIA packet;
        packet.readData(data);
        queue->push_back(packet, true);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
