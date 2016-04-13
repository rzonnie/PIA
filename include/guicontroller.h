#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <stdio.h>
#include <iostream>
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <vector>

#include "ChatHistory.h"
#include "../include/mainwindow.h"
#include "QueueController.h"
#include "RoutingTable.h"

class GUIController
{
public:
    GUIController(int argc, char *argv[], QueueController* queueController, RoutingTable* routingTable);
    void startGui();
    void setQueueController(QueueController* queueController);
private:
    int argc;
    char **argv;
    QueueController* queueController;
    RoutingTable* routingTable;
};

#endif // GUICONTROLLER_H
