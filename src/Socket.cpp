#include "../include/Socket.h"

Socket::Socket() {
    initializeSocket();
}

Socket::Socket(Settings* settings, DynamicQueue* queue)
: ThreadRunner(settings), queue(queue) {
    initializeSocket();
}

Socket::~Socket() {
    if (sockID != -1)
        close(sockID);
    std::cout << "Thread " << sockID << " has been closed" << std::endl;
}

void Socket::initializeSocket() {
    try {
        /**
         * Create a new datagram socket
         */
        if ((sockID = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
            throw std::runtime_error("Socket creation failed");
    } catch (std::exception &e) {
        std::cout << "Socket Error: " << e.what() << std::endl;
    }
}


