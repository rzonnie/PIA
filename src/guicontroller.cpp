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
				//clear the chatwindow
				
				//ask for a new chathistory
                std::vector<ChatMessage> toDisplay = ptrHistory->getChatHistory(ptrWindow->getNewCurrentUser());
                currentUser = ptrWindow->getNewCurrentUser();
				
				//display it in the chatwindow
                //  ... (toDisplay);
			}
		}
}
	
//void chatHistory
