/* 
 * File     : TerminalGUI.cpp
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 4:08 PM
 */

#include "../include/TerminalGUI.h"

TerminalGUI::TerminalGUI(Settings *handleToSettings, RoutingTable *HandleToRT) {
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

void TerminalGUI::commandsListener() const {
	std::string userInput;
	std::cin >> userInput;
	std::cout << "Command: " << userInput << std::endl;
	switch (userInput) 
	{
		case '1': // 1 Displays the 'help' message
		{
			help();
		}
		case '2': // 2 Displays the devices we can access
		{
			for (auto element: routingTablePtr->getRoutingTable())
			{
				printf("%u\n" , element.to);
			}
		}
		case '3': // 3 Lists the settings
		{
			std::cout << settingsPtr->getMulticastGroup() << std::endl;
			std::cout << settingsPtr->getLocalIP() << std::endl;
			std::cout << settingsPtr->getPort() << std::endl;
			std::cout << settingsPtr->getUsername() << std::endl;
		}
		case '4': //Quits. Sets a boolean on false which we might need to send to the PIA engine
		{
			std::cout << "Exit Program" <<  std::endl;
			alive = false;
		}
		default:
		{
			//Praten.
		}
}
