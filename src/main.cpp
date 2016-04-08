/* 
 * File:   main.cpp
 * Author: Remi jonkman
 * Group: 9
 * Created on April 6, 2016, 10:40 AM
 */

#include "../include/main.h"
#include "../include/SendSocket.h"
#include <arpa/inet.h>
#include "DynamicQueue.h"

Settings settings;
int main(int argc, char** argv) {
    // Create a namespace alias
    namespace po = boost::program_options;

    po::options_description desc("Allowed PIA Options");

    //Add all allowed command line options
    desc.add_options()
            ("help", "Prints this help message")
            ("port", po::value<int>()->default_value(14000), "Port number")
            ("ip", po::value<std::string>()->default_value("192.168.5.2"), "Local IP address")
            ("mgroup", po::value<std::string>()->default_value("228.1.2.3"), "Multicast group you want to use")
            ("username", po::value<std::string>()->default_value("PIA"), "Temporary Username");

    // Create a boost supplied options map
    po::variables_map vm;

    // Fill the boost options map
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    // Check for the help flag
    if (vm.count("help")) {
        std::cout << desc << "\n";
    } else if (vm.count("port") && vm.count("port") && vm.count("ip") && vm.count("username")) {
        // Now all mandatory flags have been set
        settings = Settings(vm["username"].as<std::string>(), vm["port"].as<int>(), vm["ip"].as<std::string>(), vm["mgroup"].as<std::string>());
        PIAEngine engine;
        engine.run();
    }

    PIA piapacket(
    		10234, //IPaddr
			100, //sequencenr
			20, //acknr
			true, //ACK flag
			true, //NTA flag
			"hi there" //payload
			);

    piapacket.setDestinationAddress(inet_addr("192.168.5.1"));
    std::string payload = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque ut nunc vel lacus maximus blandit id ut diam. In hac habitasse platea dictumst. Praesent maximus elit quam, eget fringilla ex blandit ut. Proin interdum sollicitudin est, id ultrices arcu vestibulum et. Duis dignissim sapien et massa mattis hendrerit. Etiam congue ante mi, eget lacinia mi tincidunt in. Praesent tempor ante ligula, ut tincidunt turpis fermentum et. Nam convallis metus neque, ac tincidunt sapien sodales et. Maecenas ultricies felis odio, a porta mi varius vitae. Duis ullamcorper massa diam. Suspendisse vehicula blandit tempus. Aenean egestas libero nec condimentum efficitur. Quisque commodo nunc vitae ultrices pretium. Mauris fringilla lectus semper, facilisis nunc nec, consequat sem. Phasellus ultricies dolor in vehicula condimentum. Ut mi metus, ultrices nec nunc eu, tincidunt efficitur nunc. Curabitur lacinia in urna a gravida. Nam porttitor arcu et rutrum convallis. Quisque viverra elit turpis, sed cursus nisi feugiat eu. Praesent ac cursus enim. Nullam id mattis sem, sed sollicitudin lorem. Duis tempus sem sit amet augue blandit, ac accumsan neque lacinia. Nulla facilisi. Aenean at vulputate turpis. Phasellus nec velit ac ex vulputate luctus vitae et elit. Nam accumsan vitae lectus ac dignissim. Phasellus sagittis molestie elit, a venenatis orci volutpat at. Donec commodo quam a ante ultricies, a mollis neque vulputate. Duis vel augue ac diam condimentum pulvinar id in quam. In ullamcorper lectus sit amet porttitor volutpat. Aenean volutpat est ac orci interdum malesuada. Nam nibh enim, aliquet et mi at, imperdiet mattis massa. Quisque placerat molestie sollicitudin. In ullamcorper arcu nibh, vel placerat lacus lobortis in.";
    piapacket.setPayload(payload);
    piapacket.printPacket();
    
    //SendSocket tempSocket(&settings);
    //tempSocket.sendPacket(piapacket);

    DynamicQueue dq;
    dq.addToQueue(piapacket);
    
    SendSocket tempSocket(&settings);
    tempSocket.sendPacket(piapacket);

    return 0;
}

