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
}

PIAEngine::~PIAEngine() {
}

void PIAEngine::run() {

    TerminalGUI gui(settings, &routingTable);
    bool quit = false;
    
    PIA piapacket(
            inet_addr("192.168.5.1"), //IPaddr
            100, //sequencenr
            20, //acknr
            true, //ACK flag
            true, //NTA flag
            "hi there" //payload
            );
    
    dynamicQueue.push_back(piapacket, 0);
    
    while (!quit) {
        gui.commandsListener();
        quit = !gui.getAlive();
    }
}


