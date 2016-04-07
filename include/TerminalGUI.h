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

class routingTable; //Implicit class definition

class Settings;

class TerminalGUI {
public:
	TerminalGUI(Settings *handleToSettings, routingTable *HandleToRT); //Unfortunately not with capital 'r'...
    
	/**
	* Print the help text in terminal
	*/
	void help() const;
    
	void commandsListener() const;

	bool getAlive();
private:
	bool alive;
	Settings *settingsPtr;
	routingTable *routingTablePtr;
};

#endif	/* TERMINALGUI_H */

