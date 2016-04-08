#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sstream>

void printIP(long int inetaddr) 
{
	std::ostringstream output;
	output << ((inetaddr >> 0) & 0xFF) << ".";
	output << ((inetaddr >> 8) & 0xFF) << ".";
	output << ((inetaddr >> 16) & 0xFF) << ".";
	output << ((inetaddr >> 24) & 0xFF) << " ";
	std::cout << output.str() << std::endl;
}