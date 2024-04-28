#ifndef PACKETSNIFFER_H
#define PACKETSNIFFER_H

#include <string>
#include <vector>
#include "observer.h"
#include <cstdint>
#include <functional>
#include <sys/socket.h>
#include <netinet/in.h>
#include <linux/if_packet.h>
#include <net/ethernet.h> /* the L2 protocols */
#include "observer.h"

class PacketSniffer
{
public:
    PacketSniffer(const std::string &interface);
    ~PacketSniffer();
    void registerObserver(Observer *observer);
    void listen();

private:
    int sock;              
    std::string interface; // Network interface name
    std::vector <Observer*>observers;                              // Vector to store observers
    void notifyAll(const std::vector<uint8_t> &data); // Method to notify all observers
    void bindInterface();                             // Method to bind the socket to the network interface
};

#endif