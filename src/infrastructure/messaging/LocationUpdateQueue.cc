#include "LocationUpdateQueue.h"

namespace infrastructure { namespace messaging {

void LocationUpdateQueue::push(int driver_id, const domain::geo::GeoPoint& loc) {
    auto* mem = pool_.allocate();
    if (!mem) return;                              // pool exhausted — silent drop
    new(mem) LocationUpdate{driver_id, loc};       // placement new
    {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(mem);
    }
    cv_.notify_one();
}

std::optional<LocationUpdate> LocationUpdateQueue::pop(std::chrono::milliseconds timeout) {
    std::unique_lock<std::mutex> lock(mutex_);
    if (!cv_.wait_for(lock, timeout, [&]{ return !queue_.empty() || stopped_; }))
        return std::nullopt;
    if (stopped_ && queue_.empty()) return std::nullopt;
    LocationUpdate* ptr = queue_.front();
    queue_.pop();
    LocationUpdate val = *ptr;
    ptr->~LocationUpdate();
    pool_.deallocate(ptr);
    return val;
}

void LocationUpdateQueue::stop() noexcept {
    std::unique_lock<std::mutex> lock(mutex_);
    stopped_ = true;
    cv_.notify_all();
}

}} // namespace
