#ifndef SOCKET_H
#define SOCKET_H

class Socket
{
    public:
        Socket(bool sendingSocket, string ip, uint port, string group);
        ~Socket();
    protected:
        void makeSocket(int SocketNumber);
        void sendPacket(std::string message);
};

#endif // SOCKET_H
