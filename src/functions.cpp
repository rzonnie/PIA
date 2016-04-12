#include "../include/functions.h"

std::string printIP(long int inetaddr) {
    std::ostringstream output;
    output << ((inetaddr >> 0) & 0xFF) << ".";
    output << ((inetaddr >> 8) & 0xFF) << ".";
    output << ((inetaddr >> 16) & 0xFF) << ".";
    output << ((inetaddr >> 24) & 0xFF) << " ";
    return output.str();
}