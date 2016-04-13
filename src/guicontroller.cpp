#include "../include/guicontroller.h"


GUIController::GUIController(int argc, char *argv[])
{
	startGui(argc, argv);
}

void GUIController::startGui(int argc, char *argv[])
{
    std::cout << "startingGUI" << std::endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
}
