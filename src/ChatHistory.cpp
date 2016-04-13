#include "../include/ChatHistory.h"

ChatHistory::ChatHistory()
{
	
}

void ChatHistory::AddToHistory(QString sentBy, QString message, int ID)
{
	ChatMessage newMessage;
    newMessage.user = sentBy;
	newMessage.message = message;
    std::cout << "ID: " << ID << std::endl << "Number of users with a history: " << MessagesAndTimes.size() << std::endl;
    std::cout << "number of messages in this history: " << MessagesAndTimes[ID].size() << std::endl;
    MessagesAndTimes[ID].push_back(newMessage);
}

std::vector<ChatMessage> ChatHistory::getChatHistory(int ID)
{
	return MessagesAndTimes[ID];
}

