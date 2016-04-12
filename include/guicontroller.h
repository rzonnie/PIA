#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

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

private:
	void startGui(int argc, char *argv[]);
	void toDisplay();
	void monitorGui();
	int currentUser;
	bool quit;
	MainWindow* ptrWindow;
    ChatHistory* ptrHistory;

};

#endif // GUICONTROLLER_H
