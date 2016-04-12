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
}

PIAEngine::~PIAEngine() {
}

void PIAEngine::run() {

    //TerminalGUI gui(settings, &routingTable);
    bool quit = false;
    

    PIA defaultPacket(
    		256, //SOURCE
            inet_addr("192.168.5.1"), //IPaddr
            10033, //sequencenr
            2032, //acknr
            false, //ACK flag
            false, //NTA flag
            "Bartje Partje" //payload
            );

    PIA ackPacket(
    		settings->getLocalIP(), //SOURCE
            inet_addr("192.168.5.5"), //IPaddr
            100, //sequencenr
            20, //acknr
            true, //ACK flag
            false, //NTA flag
            "Dell Vostro" //payload
            );
    
    while (!quit) {
        //gui.commandsListener();
        //quit = !gui.getAlive();

        //sendQueue.push_back(defaultPacket, 1);
        sendQueue.push_back(ackPacket, 1);
        sleep(1);
    }
}


