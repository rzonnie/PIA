#include "../include/RoutingTable.h"
#include <iostream>

using namespace std;

int main()
{
	//Simulation of 4 users with their own tables
	int OlafID = 1;
	int GuidoID = 2;
	int RemiID = 3;
	int BartID = 4;
	routingTable OlafsRoutingTable(OlafID);
	routingTable GuidosRoutingTable(GuidoID);
	routingTable RemisRoutingTable(RemiID);
	routingTable BartsRoutingTable(BartID);
	
	//Olaf is going to receive Guido's Routing Table. Let's see how he handles it.
	OlafsRoutingTable.updateRoutingTable(GuidosRoutingTable.getRoutingTable());
	//Let's print it
	int i;
	for (auto element: OlafsRoutingTable.getRoutingTable())
	{
		printf("%u %u %u\n" , element.to, element.via, element.distance);
	}
	cout <<  " " << endl;
	
	//Now Guido is going to receive Remi's Routing Table. Then afterwards, Olaf receives Guido's again.
	GuidosRoutingTable.updateRoutingTable(RemisRoutingTable.getRoutingTable());
	cout <<  " " << endl;
	OlafsRoutingTable.updateRoutingTable(GuidosRoutingTable.getRoutingTable());
	//Let's print it
	for (auto element: OlafsRoutingTable.getRoutingTable())
	{
		printf("%u %u %u\n" , element.to, element.via, element.distance);
	}
	cout <<  " " << endl;
	for (auto element: GuidosRoutingTable.getRoutingTable())
	{
		printf("%u %u %u\n" , element.to, element.via, element.distance);
	}
	cout <<  " " << endl;
	for (auto element: RemisRoutingTable.getRoutingTable())
	{
		printf("%u %u %u\n" , element.to, element.via, element.distance);
	}
	cout <<  " " << endl;
	
	//Now Remi is going to receive Bart's Routing Table. Then afterwards, same shit. 
	RemisRoutingTable.updateRoutingTable(BartsRoutingTable.getRoutingTable());
	cout <<  " " << endl;
	GuidosRoutingTable.updateRoutingTable(RemisRoutingTable.getRoutingTable());
	cout <<  " " << endl;
	OlafsRoutingTable.updateRoutingTable(GuidosRoutingTable.getRoutingTable());
	
	//Let's print it
	for (auto element: OlafsRoutingTable.getRoutingTable())
	{
		printf("%u %u %u\n" , element.to, element.via, element.distance);
	}
	cout <<  " " << endl;
	for (auto element: GuidosRoutingTable.getRoutingTable())
	{
		printf("%u %u %u\n" , element.to, element.via, element.distance);
	}
	cout <<  " " << endl;
	for (auto element: RemisRoutingTable.getRoutingTable())
	{
		printf("%u %u %u\n" , element.to, element.via, element.distance);
	}
	cout <<  " " << endl;
	for (auto element: BartsRoutingTable.getRoutingTable())
	{
		printf("%u %u %u\n" , element.to, element.via, element.distance);
	}
	cout <<  " " << endl;
	
	//Now Olaf is going to receive Bart's Routing Table Directly. Will he update?
	OlafsRoutingTable.updateRoutingTable(BartsRoutingTable.getRoutingTable());
	cout <<  " " << endl;
	for (auto element: OlafsRoutingTable.getRoutingTable())
	{
		printf("%u %u %u\n" , element.to, element.via, element.distance);
	}
	return 0;
}