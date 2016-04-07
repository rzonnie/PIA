#include <vector>
#include "RoutingTableStruct.h" 

using namespace std;

class routingTable
{
	private:
		uint8_t myIdentifier;
		vector<RoutingTableStruct> RoutingTable;
	public:
		routingTable(int ID);
		vector<RoutingTableStruct> getRoutingTable();
		RoutingTableStruct makeStruct(uint8_t to, uint8_t via, uint8_t distance);
		void addRoutingTableStruct(RoutingTableStruct Entry);
		void setMyIdentifier(int ID);
		void updateRoutingTable(vector <RoutingTableStruct> NewRoutingTable);
};
		
	