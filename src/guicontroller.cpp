#include "../include/guicontroller.h"


GUIController::GUIController(int argc, char *argv[])
    : argc(argc), argv(argv)
{
    //startGui(argc, argv);
}

void GUIController::startGui()
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
}
