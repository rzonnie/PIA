/* 
 * File     : TerminalGUI.cpp
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 4:08 PM
 */

#include "../include/TerminalGUI.h"

TerminalGUI::TerminalGUI(Settings *handleToSettings, RoutingTable* handleToRT) {
    settingsPtr = handleToSettings;
    routingTablePtr = handleToRT;
    alive = true;
    help();
    commandsListener();
}

TerminalGUI::~TerminalGUI() {
}

bool TerminalGUI::getAlive() {
    return alive;
}

void TerminalGUI::help() const {
    printf("Welcome. PIA has a few important commands you can use to chat with someone:\n"
            "1. 'help' displays this help message\n"
            "2. 'list-devices' lists all devices you can access within this ad hoc network\n"
            "3. 'list-config' list the current config\n"
            "4. 'quit' although we assume you won't ever quit PIA\n");
}

void TerminalGUI::commandsListener() {
    std::string userInput;
    std::cin >> userInput;
    std::cout << "Command: " << userInput << std::endl;

    if (userInput == "help" || userInput == "1") {
        help();
    } else if (userInput == "list-devices" || userInput == "2") {
        for (auto element : routingTablePtr->getRoutingTable()) {
            printf("%u\n", element.to);
        }
    } else if (userInput == "list-config" || userInput == "3") {
        std::cout << settingsPtr->getMulticastGroup() << std::endl;
        std::cout << settingsPtr->getLocalIP() << std::endl;
        std::cout << settingsPtr->getPort() << std::endl;
        std::cout << settingsPtr->getUsername() << std::endl;
    } else if (userInput == "quit" || userInput == "4") {
        std::cout << "Exit Program" << std::endl;
        this->alive = false;
    }
}
