#include "outputToScreen.h"

OutputToScreen::OutputToScreen(bool displayData) : displayData(displayData) {
    std::cout << "\n[>>>] Packet Sniffer initialized. Waiting for incoming data. Press Ctrl-C to abort...\n";
}

void OutputToScreen::update(const std::vector<uint8_t>& data) {
    displayOutputHeader();
    displayProtocolInfo(data);
    if (displayData) {
        displayPacketContents(data);
    }
}

void OutputToScreen::displayOutputHeader() {
    std::time_t result = std::time(nullptr);
    std::string timestr = std::asctime(std::localtime(&result));
    timestr.pop_back();  // Remove trailing newline
    std::cout << "[>] Frame at " << timestr << ":" << std::endl;
}

void OutputToScreen::displayProtocolInfo(const std::vector<uint8_t>& data) {
    // This function should parse the packet to display protocol-specific information
    std::cout << "    [+] Protocol info: Data size = " << data.size() << " bytes" << std::endl;
}

void OutputToScreen::displayPacketContents(const std::vector<uint8_t>& data) {
    std::cout << "    [+] Packet data:" << std::endl;
    for (auto byte : data) {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;
}
