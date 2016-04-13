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

class GUIController
{
public:
	GUIController(int argc, char *argv[]);
    void startGui();

private:
    int argc;
    char **argv;

};

#endif // GUICONTROLLER_H
