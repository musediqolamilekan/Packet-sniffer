#include <iostream>
#include <string>
#include <unistd.h> // For getuid()
#include "packetSniffer.h"
#include "outputToScreen.h"

int main(int argc, char* argv[]) {
    std::string interface;
    bool displayData = false;

    // Manually parsing command-line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-i" || arg == "--interface") && i + 1 < argc) {
            interface = argv[++i];
        } else if (arg == "-d" || arg == "--data") {
            displayData = true;
        } else {
            std::cerr << "Unknown option: " << arg << std::endl;
            return 1;
        }
    }

    // Check for root privileges
    if (getuid() != 0) {
        std::cerr << "Error: Permission denied. This application requires administrator privileges to run." << std::endl;
        return 1;
    }

    // Initialize the packet sniffer and output handler
    PacketSniffer sniffer(interface.empty() ? "eth0" : interface); // Defaulting to eth0 if no interface is specified
    OutputToScreen output(displayData);
    sniffer.registerObserver(&output);

    // Start packet capture
    try {
        sniffer.listen();
    } catch (const std::exception& e) {
        std::cerr << "[!] Aborting packet capture: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
