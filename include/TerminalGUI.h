/* 
 * File     : TerminalGUI.h
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 4:08 PM
 */

#ifndef TERMINALGUI_H
#define	TERMINALGUI_H

#include <iostream>

class TerminalGUI {
public:
    TerminalGUI();
    virtual ~TerminalGUI();
    
    /**
     * Print the help text in terminal
     */
    void help() const;
    
    void commandsListener() const;
private:
    
};

#endif	/* TERMINALGUI_H */

