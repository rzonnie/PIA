#include "../include/functions.h"

std::string printIP(long int inetaddr) {
    std::ostringstream output;
    output << ((inetaddr >> 0) & 0xFF) << ".";
    output << ((inetaddr >> 8) & 0xFF) << ".";
    output << ((inetaddr >> 16) & 0xFF) << ".";
    output << ((inetaddr >> 24) & 0xFF) << " ";
    return output.str();
}

std::string encryptDecrypt(std::string toEncrypt, std::string password) {
    std::string key = password;
    std::string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

    return output;
}
