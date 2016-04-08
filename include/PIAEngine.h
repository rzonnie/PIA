/* 
 * File     : PIAEngine.h
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 3:55 PM
 */

#ifndef PIAENGINE_H
#define	PIAENGINE_H

#include <iostream>
#include "TerminalGUI.h"
#include "Settings.h"
#include "RoutingTable.h"
#include "DynamicQueue.h"
#include <string>
#include "SendSocket.h"
#include "RoutingTableStruct.h"
#include <thread>

class PIAEngine {
public:
    PIAEngine(Settings* settings);
    virtual ~PIAEngine();
    
    void run();
private:
    Settings* settings;
    RoutingTable routingTable = RoutingTable(3);
    DynamicQueue dynamicQueue;
    SendSocket sendTemp = SendSocket(settings, &dynamicQueue);
    std::thread sendThread = std::thread(&SendSocket::run, &sendTemp);
};

#endif	/* PIAENGINE_H */

