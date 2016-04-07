/* 
 * File     : TerminalGUI.h
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 4:08 PM
 */

#ifndef TERMINALGUI_H
#define	TERMINALGUI_H

#include <cstdlib>
#include <iostream>
#include "RoutingTable.h"
#include "Settings.h"

class TerminalGUI {
public:
	TerminalGUI(Settings *handleToSettings, RoutingTable *HandleToRT); //Unfortunately not with capital 'r'...
        virtual ~TerminalGUI();
	/**
	* Print the help text in terminal
	*/
	void help() const;
    
	void commandsListener();
	bool getAlive();
private:
	bool alive;
	Settings *settingsPtr;
	RoutingTable *routingTablePtr;
};

#endif	/* TERMINALGUI_H */

