#include "packetSniffer.h"
#include <iostream>
#include <unistd.h>    // For close()
#include <cstring>     // For memset()
#include <arpa/inet.h> // For ntohs()
#include <net/if.h>    // For if_nametoindex

PacketSniffer::PacketSniffer(const std::string &iface) : interface(iface)
{
    sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    bindInterface();
}

PacketSniffer::~PacketSniffer()
{
    close(sock);
}

void PacketSniffer::registerObserver(Observer *observer) {
    observers.push_back(observer);
}

void PacketSniffer::notifyAll(const std::vector<uint8_t> &data)
{
    for (Observer *obs : observers)
    {
        obs->update(data);
    }
}

void PacketSniffer::bindInterface()
{
    struct sockaddr_ll sll{};
    memset(&sll, 0, sizeof(sll));
    sll.sll_family = AF_PACKET;
    sll.sll_ifindex = if_nametoindex(interface.c_str());
    sll.sll_protocol = htons(ETH_P_ALL);

    if (bind(sock, (struct sockaddr *)&sll, sizeof(sll)) < 0)
    {
        perror("Socket bind failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
}

void PacketSniffer::listen()
{
    while (true)
    {
        std::vector<uint8_t> buffer(65535);
        ssize_t bytesReceived = recv(sock, buffer.data(), buffer.size(), 0);
        if (bytesReceived > 0)
        {
            buffer.resize(bytesReceived);
            notifyAll(buffer);
        }
    }
}
