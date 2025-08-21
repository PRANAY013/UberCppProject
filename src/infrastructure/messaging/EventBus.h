#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <functional>
#include <map>
#include <typeindex>
#include <memory>
#include <vector>
#include <iostream> // For demonstration

namespace infrastructure {
namespace messaging {

// Base class for all events
class Event {
public:
    virtual ~Event() = default;
};

// A simple EventBus implementation
class EventBus {
public:
    EventBus();

    // Publish an event
    void publish(const Event& event);

    // Subscribe to an event type
    template <typename EventType>
    void subscribe(std::function<void(const EventType&)> handler) {
        auto type = std::type_index(typeid(EventType));
        subscribers[type].push_back([h = std::move(handler)](const Event& e) {
            // Safely cast the base Event to the specific EventType
            if (const EventType* specificEvent = dynamic_cast<const EventType*>(&e)) {
                h(*specificEvent);
            }
        });
    }

private:
    // Map from event type to a list of handlers (functions taking a const Event&)
    std::map<std::type_index, std::vector<std::function<void(const Event&)>>> subscribers;
};

} // namespace messaging
} // namespace infrastructure

#endif // EVENTBUS_H
