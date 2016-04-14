#include "../include/guicontroller.h"


GUIController::GUIController(int argc, char *argv[], QueueController* queueController, RoutingTable* routingTable, Settings* settings, ChatHistory* chatHistory)
    : argc(argc), argv(argv), queueController(queueController), routingTable(routingTable), settings(settings), chatHistory(chatHistory)
{
    //startGui(argc, argv);
}

void GUIController::startGui()
{
    QApplication a(argc, argv);
    MainWindow w(queueController, routingTable, settings, chatHistory);
    w.show();
    a.exec();
}
