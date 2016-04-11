#ifndef FUNCTIONSOWN_H
#define	FUNCTIONSOWN_H

#include <string>
#include <iostream>
#include <sstream>

void printIP(long int inetaddr) {
    std::ostringstream output;
    output << ((inetaddr >> 0) & 0xFF) << ".";
    output << ((inetaddr >> 8) & 0xFF) << ".";
    output << ((inetaddr >> 16) & 0xFF) << ".";
    output << ((inetaddr >> 24) & 0xFF) << " ";
    std::cout << output.str() << std::endl;
}

#endif /* FUNCTIONS_H */