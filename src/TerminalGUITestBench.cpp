// Test Bench for the terminal GUI

#include "../include/TerminalGUI.h"
#include "../include/RoutingTable.h"
#include "../include/Settings.h"
#include <string>

int main()
{
	std::string username = "me";
	Settings mySettings(username, 1, 65, 0); //Username: me, port: 1, IP: 65, MulticastGroup: 0
	RoutingTable myRoutingTable(65); //Identifier: 65;
	
	Settings *handleToSettings = &mySettings; //Create handles to settings and routingtable
	RoutingTable *handleToRT = &myRoutingTable;
	
	TerminalGUI myTerminalGUI(mySettings, myRoutingTable); //Create terminal user interface
	return 0;
}