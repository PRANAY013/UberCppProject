#include "InMemoryDriverRepository.h"

namespace infrastructure {
namespace persistence {

InMemoryDriverRepository::InMemoryDriverRepository() {}

void InMemoryDriverRepository::save(const domain::Driver& driver) {
    std::unique_lock lock(rw_mutex_);
    drivers_.insert_or_assign(driver.getId(), driver);
    spatial_grid_.insert(driver);
}

std::optional<domain::Driver> InMemoryDriverRepository::findById(const int& id) const {
    std::shared_lock lock(rw_mutex_);
    auto it = drivers_.find(id);
    if (it != drivers_.end()) {
        return it->second;
    }
    return std::nullopt;
}

std::vector<domain::Driver> InMemoryDriverRepository::findAll() const {
    std::shared_lock lock(rw_mutex_);
    std::vector<domain::Driver> allDrivers;
    for (const auto& pair : drivers_) {
        allDrivers.push_back(pair.second);
    }
    return allDrivers;
}

void InMemoryDriverRepository::remove(const int& id) {
    std::unique_lock lock(rw_mutex_);
    auto it = drivers_.find(id);
    if (it != drivers_.end()) {
        spatial_grid_.remove(id, it->second.getLocation());
        drivers_.erase(it);
    }
}

std::vector<domain::Driver> InMemoryDriverRepository::findNearestInRadius(
    const domain::geo::GeoPoint& center, double radius_km) const {
    std::shared_lock lock(rw_mutex_);
    return spatial_grid_.queryNeighborhood(center, radius_km);
}

void InMemoryDriverRepository::updateDriverLocation(int driver_id, const domain::geo::GeoPoint& new_loc) {
    std::unique_lock lock(rw_mutex_);
    auto it = drivers_.find(driver_id);
    if (it != drivers_.end()) {
        auto old_loc = it->second.getLocation();
        it->second.setLocation(new_loc);
        spatial_grid_.remove(driver_id, old_loc);
        spatial_grid_.insert(it->second);
    }
}

} // namespace persistence
} // namespace infrastructure
