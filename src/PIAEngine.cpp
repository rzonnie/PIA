/* 
 * File     : PIAEngine.cpp
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 3:55 PM
 */

#include "../include/PIAEngine.h"

PIAEngine::PIAEngine(Settings* settings)
: settings(settings)
{
    std::cout << "START" << std::endl;
}

PIAEngine::~PIAEngine() {
}

void PIAEngine::run(int argc, char *argv[]) {
    std::thread sendThread(&SendSocket::run, &sendTemp);
    sendThread.detach();

    std::thread receivingThread(&ReceivingSocket::run, &receiveTemp);
    receivingThread.detach();

    std::thread announceThread(&Announcement::run, &announcement);
    announceThread.detach();

    GUIController guiControl(argc, argv, &queueController, &routingTable, settings, &chatHistory);
    std::thread GUI(&GUIController::startGui, guiControl);

    std::thread queueControllerThread(&QueueController::run, &queueController);
    queueControllerThread.detach();

    std::cout<<encryptDecrypt(encryptDecrypt("hello world, how are you doing","gehaktbal13"),"gehaktbal");
    // Wait for the GUI to be joinable
    if (GUI.joinable()) {
        GUI.join();
    }
    std::cout << "CLOSING" << std::endl;
}


