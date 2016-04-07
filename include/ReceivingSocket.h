#ifndef RECEIVINGSOCKET_H
#define RECEIVINGSOCKET_H


class ReceivingSocket
{
    public:
        ReceivingSocket(std::string ip, int port, std::string group);
    protected:
    private:
        int get_receive_socket(string ip, uint16_t port, string group);
        int receivePacket(string ip, uint port, string group, BlockingQueue<std::string> &q);
        bool stopReceiving;

#endif // RECEIVINGSOCKET_H
