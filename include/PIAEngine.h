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
#include "ReceivingSocket.h"
#include "Announcement.h"
#include <thread>

class PIAEngine {
public:
    PIAEngine(Settings* settings);
    virtual ~PIAEngine();
    
    void run();
private:
    Settings* settings;
    RoutingTable routingTable = RoutingTable(settings, 3);
    DynamicQueue sendQueue;
    DynamicQueue receivingQueue;
    SendSocket sendTemp = SendSocket(settings, &sendQueue);
    ReceivingSocket receiveTemp = ReceivingSocket(settings, &receivingQueue);
    Announcement announcement = Announcement(settings, &sendQueue, &routingTable);
    
    std::thread sendThread = std::thread(&SendSocket::run, &sendTemp);
    std::thread receivingThread = std::thread(&ReceivingSocket::run, &receiveTemp);
    std::thread announceThread = std::thread(&Announcement::run, &announcement);
};

#endif	/* PIAENGINE_H */

