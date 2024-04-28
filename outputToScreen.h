#ifndef OUTPUTTOSCREEN_H
#define OUTPUTTOSCREEN_H

#include "observer.h"
#include <iostream>
#include <vector>
#include <cstdint>
#include <ctime>

class OutputToScreen : public Observer {
public:
    explicit OutputToScreen(bool displayData);
    void update(const std::vector<uint8_t>& data) override;

private:
    bool displayData;

    void displayOutputHeader();
    void displayProtocolInfo(const std::vector<uint8_t>& data);
    void displayPacketContents(const std::vector<uint8_t>& data);
};

#endif // OUTPUTTOSCREEN_H
