/* 
 * File     : PIAEngine.h
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 3:55 PM
 */

#ifndef PIAENGINE_H
#define	PIAENGINE_H

#include "RoutingTableStruct.h"


#include <iostream>
#include "TerminalGUI.h"
#include "Settings.h"
#include "RoutingTable.h"
#include <string>

class PIAEngine {
public:
    PIAEngine();
    virtual ~PIAEngine();
    
    void run();
private:
    Settings settings;
    RoutingTable routingTable = RoutingTable(3);
};

#endif	/* PIAENGINE_H */

