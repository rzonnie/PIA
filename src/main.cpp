/* 
 * File:   main.cpp
 * Author: Remi jonkman
 * Group: 9
 * Created on April 6, 2016, 10:40 AM
 */

#include "../include/main.h"
#include <bitset>

Settings settings;
int main(int argc, char** argv) {
    // Create a namespace alias
    namespace po = boost::program_options;

    po::options_description desc("Allowed PIA Options");

    //Add all allowed command line options
    desc.add_options()
            ("help", "Prints this help message")
            ("port", po::value<int>()->default_value(14000), "Port number")
            ("ip", po::value<std::string>()->default_value("192.168.5.1"), "Local IP address")
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
    
    std::string concatenate, henk = "henk", anja = "anja";
    std::bitset<32> henkBit(henk.c_str());
    //std::bitset<32> anjaBit("anja");
    //concatenate  << henk << anja;
    //concatenate = "asdfasd" + henk;
    //std::cout << "Error: " << henkBit << std::endl;
    

    //PIA piapacket;
    //std::cout<<piapacket.getData();

    return 0;
}

