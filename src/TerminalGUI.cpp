/* 
 * File     : TerminalGUI.cpp
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 4:08 PM
 */

#include "../include/TerminalGUI.h"

TerminalGUI::TerminalGUI() {
    help();
    commandsListener();
}

TerminalGUI::~TerminalGUI() {
}

void TerminalGUI::help() const {
    printf("Welcome. PIA has a few important commands you should use to chat with someone:\n"
            "1. 'help' displays this help message\n"
            "2. 'list-devices' lists all devices you can access within this ad hoc network\n"
            "3. 'list-config' list the current config\n"
            "4. 'quit' although we assume you won't ever quit PIA\n");
}

void TerminalGUI::commandsListener() const {
    std::string henk;
    std::cin >> henk;
    std::cout << "Command: " << henk << std::endl;
}
