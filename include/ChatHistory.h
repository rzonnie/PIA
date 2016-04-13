#ifndef CHATHISTORY_H
#define CHATHISTORY_H

#include <vector>
#include <QString>
#include <array>
#include <map>
#include "chatmessage.h"
#include <iostream>

class ChatHistory
{
public:
        ChatHistory();
        std::vector<ChatMessage> getChatHistory (int);
        void AddToHistory (QString user, QString message, int ID);


private:
    std::map<int, std::vector<ChatMessage> > MessagesAndTimes;
};

#endif // CHATHISTORY_H
