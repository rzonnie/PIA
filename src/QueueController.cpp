#include "../include/QueueController.h"

QueueController::QueueController(Settings* settings, DynamicQueue* sendQueue, DynamicQueue* receivingQueue, RoutingTable* routingTable)
: ThreadRunner(settings), sendQueue(sendQueue), receivingQueue(receivingQueue), routingTable(routingTable) {
    //MaxQueueSize = MQZ;
    //MaxPacketLength = MPL;
}

QueueController::~QueueController() {
};

void QueueController::run() {
    while (true) {
        //routingTable->printRoutingTable();
        std::cout << "Queue controller: retrieving packets" << std::endl;
        PIA packet = receivingQueue->retrievePacket();

        if (packet.isNta()){
            ntaChecker(packet);
        }
        
        std::cout << "Queue controller: sleep 1 second" << std::endl;
        sleep(1);
    }
}

std::vector<std::string> QueueController::packetSplitter(std::string chatpayload)
{
	// Create result and temp vectors/strings. Push contents of chatpayload in temp and pushback temp onto result whenever size of temp is MTU.
	std::vector<std::string> result;
	std::string temp;
	unsigned int iterator = 0;
	while( iterator < charpayload.size())
	{
		if(temp.size() == settings->getMTU())
		{
			result.push_back(temp);
			temp = "";
		}
		temp = temp + charpayload[iterator];
	}		
	//Also send the last few bits of data from chatpayload
	result.push_back(temp);
	return result;
}

std::vector<PIA> QueueController::packetCreator(uint32_t destinationIP, uint32_t SequenceNumber, uint32_t AckNumber, bool ACK, bool NTA, std::vector<std::string> result)
{
	//Creates packets based on input variables.
	std::vector<PIA> PIAPackets;
	for (auto i: result)
	{
		PIA newPIAPacket(destinationIP, SequenceNumber, AckNumber, Ack, NTA, i);
		PIAPackets.push_back(newPIAPacket);
	}
	return PIAPackets;
}

void QueueController::packetPusher(PIA &packet)
{
}

uint32_t QueueController::sequenceNumberGenerator(
{
	//SeqNumber 1 high than previous or not
}

void QueueController::ntaChecker(PIA &packet) {
    std::cout << "Still alive" << std::endl;
    // Create a temporary RoutingTable
    RoutingTable temp;

    // Open an input stringstream
    std::istringstream payload(packet.getPayload());

    // Interpret the archive information inside the stream
    boost::archive::text_iarchive archive(payload);

    // Stream the archive to the temporary routing table
    archive >> temp;

    //temp.printRoutingTable();
    // Now update the actual routing table
    routingTable->updateRoutingTable(temp);
    routingTable->printRoutingTable();

    //std::cout << "Routing table updated by host: ";
    //printIP(temp.getMyIdentifier());
    //std::cout << temp.getMyIdentifier() << std::endl;
}

void QueueController::ackChecker(PIA &packet){
	uint32_t ackNumber = packet.getAcknowledgementNumber();
	sendQueue->defaultQueueAck(ackNumber);
}
