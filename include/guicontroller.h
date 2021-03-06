#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <stdio.h>
#include <iostream>
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <vector>
#include <string>

#include "ChatHistory.h"
#include "../include/mainwindow.h"
#include "QueueController.h"
#include "RoutingTable.h"
#include "Settings.h"

class GUIController
{
public:
    GUIController(int argc, char *argv[], QueueController* queueController, RoutingTable* routingTable, Settings* settings, ChatHistory* chatHistory);
    void startGui();
private:
    int argc;
    char **argv;
    QueueController* queueController;
    RoutingTable* routingTable;
    Settings* settings;
    ChatHistory* chatHistory;
};

#endif // GUICONTROLLER_H
