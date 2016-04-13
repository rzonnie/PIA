/* 
 * File     : PIAEngine.cpp
 * Author   : Guido Kuijper, Olaf van der Meer, Bart van der Scheer and Remi Jonkman
 * Group    : 9
 *
 * Created on April 6, 2016, 3:55 PM
 */

#include "../include/PIAEngine.h"

PIAEngine::PIAEngine(Settings* settings)
: settings(settings)
{
    std::cout << "START" << std::endl;
}

PIAEngine::~PIAEngine() {
}

void PIAEngine::run() {

    std::thread sendThread(&SendSocket::run, &sendTemp);
    std::thread receivingThread(&ReceivingSocket::run, &receiveTemp);
    std::thread announceThread(&Announcement::run, &announcement);
    std::thread queueControllerThread(&QueueController::run, &queueController);

    sendThread.detach();
    receivingThread.detach();
    queueControllerThread.detach();
    announceThread.detach();

    //TerminalGUI gui(settings, &routingTable);
    bool quit = false;


    /*PIA defaultPacket(
            settings->getLocalIP(), //SOURCE
            inet_addr("192.168.5.5"), //IPaddr
            10033, //sequencenr
            2032, //acknr
            false, //ACK flag
            false, //NTA flag
            "doeasdfasdfdsai" //payload
            );*/

    std::string input = "he pik, Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla dui dui, commodo quis massa vitae, blandit ultricies urna. Fusce eget ligula id justo sodales ultricies sit amet non felis. Maecenas hendrerit gravida neque, quis rhoncus eros faucibus eget. Vivamus sed vulputate ante. Quisque sed semper nunc. Pellentesque pulvinar auctor lorem quis venenatis. Quisque arcu nulla, sodales ut euismod ac, placerat ac nisi. Integer ultrices metus at sapien varius consequat. Sed rhoncus faucibus est, vel sodales nunc elementum vel. Pellentesque nec velit tellus. Aliquam faucibus lacus a interdum vulputate. Vestibulum vel commodo lectus, sed vestibulum sapien. Sed gravida justo libero, nec tempus mi efficitur sed. Proin egestas nisi eget eros ultricies, nec fermentum augue mattis. Nullam quis urna sed dolor pharetra mattis. Quisque lobortis et dui ut cursus. Donec suscipit pulvinar gravida. Nulla laoreet enim velit, vitae iaculis sem aliquam et. Interdum et malesuada fames ac ante ipsum primis in faucibus. Duis consectetur tempus leo, sit amet interdum diam condimentum et. Maecenas non nibh in mauris iaculis ultricies pellentesque nec sapien. Ut pulvinar justo a ultrices ultrices. Curabitur turpis velit, eleifend non justo in, fermentum suscipit mi. Morbi a auctor erat. Morbi pellentesque odio magna, vel luctus lorem porttitor a. Proin malesuada eleifend purus tristique sollicitudin. Mauris venenatis odio id turpis maximus consectetur. Nullam maximus, erat non tincidunt lacinia, nibh justo tristique ligula, vel accumsan lorem tellus vitae ante. Maecenas laoreet iaculis est, at dignissim felis pretium eu. Curabitur non egestas diam. Aliquam eu rutrum libero. Mauris posuere feugiat purus et condimentum. Cras porttitor ex ut nulla ultrices mattis. Curabitur metus purus, rhoncus a placerat at, laoreet id justo. In hac habitasse platea dictumst. Nullam hendrerit leo eu aliquet dictum. Sed varius nunc nunc. In tortor dui, tincidunt in vehicula eu, elementum sit amet lorem. In accumsan ante sem, at pulvinar mi molestie quis. Sed lacinia malesuada rutrum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque placerat erat nulla, sit amet ultrices diam ornare in. Nunc id elit a leo commodo feugiat. Nunc porttitor tellus in nisl ornare, ac ornare sem hendrerit. Donec id volutpat mi, nec faucibus purus. Morbi sodales ligula ac eros imperdiet, nec molestie tellus egestas. Maecenas vitae pulvinar erat. Vivamus non risus viverra, tincidunt ex at, tincidunt ipsum. Nullam blandit elit lectus. Aliquam auctor congue gravida. Vivamus nec nunc laoreet, faucibus dui ut, fringilla justo. Vivamus maximus tellus non ligula rutrum placerat. Pellentesque porta lorem et malesuada hendrerit. Maecenas ut elit dictum, malesuada nisi nec, facilisis orci. Duis tempor eros nulla. Nunc luctus aliquam felis, in congue elit accumsan a. Nam tincidunt dapibus quam, eget maximus neque vulputate quis. Donec ultricies libero eget lectus tempor maximus. Phasellus cursus ultricies nibh a congue. Mauris mi sem, aliquam ac faucibus eu, pulvinar at turpis. Integer et laoreet enim. Nam a facilisis mauris. Quisque porttitor eleifend ligula dictum placerat. Fusce lobortis urna sit amet nisl cursus pharetra. Quisque tincidunt risus et ipsum dictum, id pharetra felis tristique. Sed convallis sagittis lacinia. Quisque id arcu nunc. Sed vitae nulla condimentum, vestibulum quam non, ultricies magna. Vestibulum rutrum varius interdum. Morbi volutpat, lacus a consectetur consectetur, nisi arcu maximus ante, et consequat sapien massa ut urna. Aenean lorem nulla, euismod quis mattis vitae, convallis id augue. Donec at sagittis nunc. Aliquam consequat semper lorem, sed ultrices erat pulvinar et. Suspendisse mollis lectus a massa tincidunt, non dignissim velit varius. Suspendisse suscipit odio quis augue accumsan viverra. Mauris ut orci et sem dapibus egestas sit amet eget mauris. Phasellus ultricies aliquam ante id molestie. Donec a nunc varius, suscipit ex sit amet, volutpat augue volutpat.";
    //queueController.sendData(input,inet_addr("192.168.5.4"));

    //sendQueue.push_back(defaultPacket, 0);
       while (!quit) {
        //gui.commandsListener();
        //quit = !gui.getAlive();
        sendQueue.printDefaultQueue();
        std::cout << "PiaEngine Queue size: " << sendQueue.size_default() << std::endl;
        //sendQueue.printDefaultQueue();
        sleep(1);
    }
}


