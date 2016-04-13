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
        std::vector<ChatMessage> getChatHistory (QString ID);
        void AddToHistory(QString sentBy, QString message, QString ID);


private:
    std::map<QString, std::vector<ChatMessage> > MessagesAndTimes;
};

#endif // CHATHISTORY_H
