/* 
 * File     : PIAEngine.cpp
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 3:55 PM
 */

#include "../include/PIAEngine.h"

PIAEngine::PIAEngine(Settings* settings)
: settings(settings)
{
    std::cout << "START" << std::endl;
}

PIAEngine::~PIAEngine() {
}

void PIAEngine::run(int argc, char *argv[]) {
    std::thread sendThread(&SendSocket::run, &sendTemp);
    sendThread.detach();

    std::thread receivingThread(&ReceivingSocket::run, &receiveTemp);
    receivingThread.detach();

    std::thread announceThread(&Announcement::run, &announcement);
    announceThread.detach();

    GUIController guiControl(argc, argv, &queueController, &routingTable, settings, &chatHistory);
    std::thread GUI(&GUIController::startGui, guiControl);

    std::thread queueControllerThread(&QueueController::run, &queueController);
    queueControllerThread.detach();

    //Encryption variables
    bool err;
    string errMsg;
    string key = BasicCryptoPPWrap::BitGen(128);   // We'll make a random 128 bit key
    string initVector = BasicCryptoPPWrap::ByteGen(16); // AES uses 16 byte blocks, so the initVector must be 16 bytes

    //encrypt
    std::cout << "\nkey1: " << BasicCryptoPPWrap::HexEncode(key) << "\n";
    std::cout << "initVec1: " << BasicCryptoPPWrap::HexEncode(initVector) << "\n";
    string cipherText = BasicCryptoPPWrap::EncryptStringAES("Encrypt me", key, initVector, err, errMsg);
    string recoveredText = BasicCryptoPPWrap::DecryptStringAES(cipherText, key, initVector,  err, errMsg);

    std::cout<<BasicCryptoPPWrap::HexEncode(cipherText);
    std::cout<<"Recovered Text:"<<recoveredText<<std::endl;

    // Wait for the GUI to be joinable
    if (GUI.joinable()) {
        GUI.join();
    }
    std::cout << "CLOSING" << std::endl;
}


