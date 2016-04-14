/* 
 * File     : Settings.cpp
 * Author   : Remi Jonkman
 * Group    : 9
 * 
 * Created on April 6, 2016, 11:50 AM
 */

#include "../include/Settings.h"

Settings::Settings() {

}

Settings::Settings(std::string username, int port, std::string localIP, std::string multicastGroup) {
    setUsername(username);
    setPort(port);
    setLocalIP(localIP);
    setMulticastGroup(multicastGroup);
}

Settings::~Settings() {
}

// Below here are only getters and setters
void Settings::setMulticastGroup(std::string multicastGroup) {
    this->multicastGroup = inet_addr(multicastGroup.c_str());
}

int Settings::getMulticastGroup() {
    return multicastGroup;
}

void Settings::setLocalIP(std::string localIP) {
    this->localIP = inet_addr(localIP.c_str());
}

int Settings::getLocalIP() {
    return localIP;
}

void Settings::setPort(int port) {
    this->port = port;
}

int Settings::getPort() {
    return port;
}

void Settings::setUsername(std::string username) {
    this->username = username;
}

std::string Settings::getUsername() {
    return username;
}

uint16_t Settings::getMTU() const {
    return MTU;
}

int16_t Settings::getInfinite() const {
    return infinite;
}
