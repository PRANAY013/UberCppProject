#include "EventBus.h"

namespace infrastructure {
namespace messaging {

EventBus::EventBus() {}

void EventBus::publish(const Event& event) {
    auto type = std::type_index(typeid(event));
    if (subscribers.count(type)) {
        for (const auto& handler : subscribers[type]) {
            handler(event);
        }
    }
}

} // namespace messaging
} // namespace infrastructure
