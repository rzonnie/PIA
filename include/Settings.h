/* 
 * File:   Settings.h
 * Author: remi
 *
 * Created on April 6, 2016, 11:50 AM
 */

#ifndef SETTINGS_H
#define	SETTINGS_H

#include <string>
#include <iostream>
#include <arpa/inet.h>
#include <bitset>

class Settings {
public:
    Settings();
    
    /**
     * Simple constructor. It automatically converts human readable ip addresses to 
     * network format.
     * @param username std::string your username
     * @param port int port number
     * @param localIP std::string ip address of your computer
     * @param multicastGroup std::string ip address for the multicast group
     */
    Settings(std::string username, int port, std::string localIP, std::string multicastGroup);
    virtual ~Settings();
    
    // Getters and setters
    void setMulticastGroup(std::string multicastGroup);
    int getMulticastGroup();
    void setLocalIP(std::string localIP);
    int getLocalIP();
    void setPort(int port);
    int getPort();
    void setUsername(std::string username);
    std::string getUsername();
private:
    std::string username;
    uint32_t port;
    
    // Network Readable IP addresses
    uint32_t localIP;
    uint32_t multicastGroup;
};

#endif	/* SETTINGS_H */

