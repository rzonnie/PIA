#ifndef SOCKET_H
#define SOCKET_H

#include <exception>
#include <unistd.h>

#include "DynamicQueue.h"
#include "Settings.h"
#include "ThreadRunner.h"

class Socket : public ThreadRunner {
public:
    Socket();
    Socket(Settings *settings, DynamicQueue *queue);
    ~Socket();
protected:
    /**
     * A specific initializer for every specific socket.
     */
    virtual void init() = 0;
    
    /**
     * Initialize a general datagram socket
     */
    void initializeSocket();
    
    DynamicQueue* queue;
    int sockID = -1;
    
};

#endif // SOCKET_H
