#include "../include/guicontroller.h"


GUIController::GUIController(int argc, char *argv[], QueueController* queueController, RoutingTable* routingTable)
    : argc(argc), argv(argv), queueController(queueController), routingTable(routingTable)
{
    //startGui(argc, argv);
}

void GUIController::startGui()
{
    QApplication a(argc, argv);
    MainWindow w(queueController, routingTable);
    w.show();
    a.exec();
}

void GUIController::setQueueController(QueueController* queueController) {
    this->queueController = queueController;
}
