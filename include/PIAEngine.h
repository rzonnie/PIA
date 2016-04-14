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
#include "QueueController.h"
#include "ChatHistory.h"
#include "guicontroller.h"
#include "functions.h"
#include "Crypto++/BasicCryptoPPWrap.h"

class PIAEngine {
public:
    PIAEngine(Settings* settings);
    virtual ~PIAEngine();
    
    void run(int argc, char *argv[]);
private:
    Settings* settings;
    RoutingTable routingTable = RoutingTable(settings, settings->getLocalIP());
    DynamicQueue sendQueue;
    DynamicQueue receivingQueue;
    ChatHistory chatHistory;
    
    SendSocket sendTemp = SendSocket(settings, &sendQueue, &routingTable);
    ReceivingSocket receiveTemp = ReceivingSocket(settings, &receivingQueue);
    Announcement announcement = Announcement(settings, &sendQueue, &routingTable);
    QueueController queueController = QueueController(settings , &sendQueue, &receivingQueue, &routingTable, &chatHistory);
};

#endif	/* PIAENGINE_H */

