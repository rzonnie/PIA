#ifndef CHATHISTORY_H
#define CHATHISTORY_H
#include "../include/ChatHistory.h"

ChatHistory::ChatHistory()
{
    //const
}

void ChatHistory::AddToHistory(int time, QString message, int ID)
{
	ChatMessage newMessage;
	newMessage.time = time;
	newMessage.message = message;
    MessagesAndTimes[ID].push_back(newMessage);
}

std::vector<ChatMessage> ChatHistory::getChatHistory(int ID)
{
	return MessagesAndTimes[ID];
}

#endif // CHATHISTORY_H
