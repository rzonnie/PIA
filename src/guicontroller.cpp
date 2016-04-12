#include "../include/guicontroller.h"
#include "../include/mainwindow.h"

GUIController::GUIController(int argc, char *argv[])
{
	quit = false;
	startGui(argc, argv);
	monitorGui();
}

void GUIController::startGui(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatHistory myChatHistory;
    ptrHistory = & myChatHistory;
    MainWindow w;
    ptrWindow = &w;
    w.show();
    a.exec();
}

void GUIController::monitorGui()
{
	while(!quit)
		{
			if (ptrWindow->getNewMessage())
			{
				ptrWindow->setNewMessage(false);
				//send this string
				//add to the chat history
			}
			if (ptrWindow->getNewCurrentUser() != currentUser)
			{
				currentUser = ptrWindow->getNewCurrentUser();
				toDisplay()
			}
		}
}

void GUIController::toDisplay()
{
    std::vector<ChatMessage> toDisplay = ptrHistory->getChatHistory(ptrWindow->getNewCurrentUser());
    QString toDisplayString;
	int i;
	for (i=0;i<toDisplay.size();i++)
	{
		toDisplayString.push_back(toDisplay[0].time);
		toDisplayString.push_back(":  ");
		toDisplayString.push_back(toDisplay[0].message);
		toDisplayString.push_back("/n");
	}
    ptrWindow->toDisplay(toDisplayString);
}
	
//void chatHistory
