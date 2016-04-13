/* 
 * File     : PIAEngine.cpp
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 3:55 PM
 */

#include "../include/PIAEngine.h"

PIAEngine::PIAEngine(Settings* settings)
: settings(settings) {
    sendThread.detach();
    receivingThread.detach();
    queueControllerThread.detach();
    announceThread.detach();
}

PIAEngine::~PIAEngine() {
}

void PIAEngine::run() {

    //TerminalGUI gui(settings, &routingTable);
    bool quit = false;


    PIA defaultPacket(
            settings->getLocalIP(), //SOURCE
            inet_addr("192.168.5.5"), //IPaddr
            10033, //sequencenr
            2032, //acknr
            false, //ACK flag
            false, //NTA flag
            "doeasdfasdfdsai" //payload
            );
    
    sendQueue.push_back(defaultPacket, 1);
    
    while (!quit) {
        //gui.commandsListener();
        //quit = !gui.getAlive();
        //sendQueue.printDefaultQueue();
        std::cout << "PiaEngine Queue size: " << sendQueue.size_default() << std::endl;
        //sendQueue.printDefaultQueue();
        sleep(1);
    }
}


