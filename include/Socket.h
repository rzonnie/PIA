#ifndef SOCKET_H
#define SOCKET_H

#include <exception>
#include <unistd.h>


#include "DynamicQueue.h"
#include "Settings.h"

class Socket {
public:
    Socket();
    Socket(Settings *settings, DynamicQueue *queue);
    ~Socket();

    /**
     * Every subclass should implement its own thread runner. This run function will
     * run during the entire thread life span.
     */
    virtual void run() = 0;
protected:
    /**
     * A specific initializer for every specific socket.
     */
    virtual void init() = 0;
    
    /**
     * Initialize a general datagram socket
     */
    void initializeSocket();

    Settings *settings;
    DynamicQueue* queue;
    int sockID = -1;
    bool quit = false;
};

#endif // SOCKET_H
