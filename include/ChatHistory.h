#include <vector>
#include <QString>
#include <array>
#include "chatmessage.h"

class ChatHistory
{
public:
        ChatHistory();
        std::vector<ChatMessage> getChatHistory (int);
        void AddToHistory (int time, QString message, int ID);


private:
    std::array<std::vector<ChatMessage>, 128> MessagesAndTimes;
};

