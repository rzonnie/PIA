/* 
 * File     : PIAEngine.cpp
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 3:55 PM
 */

#include "../include/PIAEngine.h"

PIAEngine::PIAEngine() {
}

PIAEngine::~PIAEngine() {
}

void PIAEngine::run() {
    
    TerminalGUI gui(&settings, &routingTable);
    bool quit = false;
    
    while (!quit) {
        gui.commandsListener();
        quit = !gui.getAlive();
    }
    
    std::cout << "Byee" << std::endl;
}


