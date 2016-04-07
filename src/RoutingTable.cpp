#include "../include/RoutingTable.h"

using namespace std;

routingTable::routingTable(int ID)
{
	setMyIdentifier(ID);
	uint8_t to = ID;
	uint8_t distance = 0;
	uint8_t via = ID;
	addRoutingTableStruct(makeStruct(to, via, distance));
}

vector<RoutingTableStruct> routingTable::getRoutingTable() 
{
	return RoutingTable;
}

void routingTable::addRoutingTableStruct(RoutingTableStruct Entry)
{
	RoutingTable.push_back(Entry);
}

void routingTable::setMyIdentifier(int ID)
{
	myIdentifier = ID;
}

RoutingTableStruct routingTable::makeStruct(uint8_t to, uint8_t via, uint8_t distance)
{
	RoutingTableStruct NewEntry;
	NewEntry.to = to;
	NewEntry.via = via;
	NewEntry.distance = distance;
	return NewEntry;
}

void routingTable::updateRoutingTable(vector <RoutingTableStruct> NewRoutingTable)
{
	int i;
	int j;
	bool newElement = false;
	for (i = 0; i <= NewRoutingTable.size(); i++) //Loop over all routing table entries
	{
		if (NewRoutingTable[i].via != myIdentifier) //This checks if this entry is not measured from me as a point to prevent loops
		{
			for (j= 0; j <= RoutingTable.size(); j++) //Loop over all routing table entries to consider if you have the destination already
			{
				if (RoutingTable[j].to = NewRoutingTable[i].to) //Check if the destination is already in your list
				{
					if (RoutingTable[j].distance > NewRoutingTable[i].distance) //Is the distance smaller?
					{
						RoutingTable.erase(RoutingTable.begin() + i - 1); //Destroy old element, possible because vector is not ordered
						RoutingTableStruct NewEntry; //Initialise New Entry
						NewEntry = makeStruct(NewRoutingTable[i].to, NewRoutingTable[0].to, NewRoutingTable[i].distance + 1); //New entry has to = to, via = to0 = ID and distance += 1
						addRoutingTableStruct(NewEntry); //Add new element
					}
					newElement = true;
				}
			}
			if (!newElement) //If j looped over the full routing table I already had, and the destination was not found there:
			{
				addRoutingTableStruct(NewRoutingTable[i]); //Add it to my routing table
			}
		}
	}
}
