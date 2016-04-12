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
    


    /*PIA piapacket(
            inet_addr("192.168.5.1"), //IPaddr
            100, //sequencenr
            20, //acknr
            true, //ACK flag
            true, //NTA flag
            "hi there" //payload
            );*/
    
    while (!quit) {
        //gui.commandsListener();
        //quit = !gui.getAlive();
    	std::cout<<"Choose option";
        sleep(1);
        //sendQueue.push_back(piapacket, 0);
    }
}


