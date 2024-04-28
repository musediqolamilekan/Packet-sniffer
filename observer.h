#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <cstdint>

#ifndef OBSERVER_CLASS_DEFINED
#define OBSERVER_CLASS_DEFINED
// Abstract base class for observers
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::vector<uint8_t>& data) = 0;
};
#endif // OBSERVER_CLASS_DEFINED

#endif // OBSERVER_H
