#include "../include/guicontroller.h"


GUIController::GUIController(int argc, char *argv[], QueueController* queueController, RoutingTable* routingTable, Settings* settings)
    : argc(argc), argv(argv), queueController(queueController), routingTable(routingTable), settings(settings)
{
    //startGui(argc, argv);
}

void GUIController::startGui()
{
    QApplication a(argc, argv);
    MainWindow w(queueController, routingTable, settings);
    w.show();
    a.exec();
}
