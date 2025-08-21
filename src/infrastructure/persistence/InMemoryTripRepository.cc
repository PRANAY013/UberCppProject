#include "InMemoryTripRepository.h"

namespace infrastructure {
namespace persistence {

InMemoryTripRepository::InMemoryTripRepository() {}

void InMemoryTripRepository::save(const domain::Trip& trip) {
    trips.insert_or_assign(trip.getId(), trip);
}

std::optional<domain::Trip> InMemoryTripRepository::findById(const int& id) const {
    auto it = trips.find(id);
    if (it != trips.end()) {
        return it->second;
    }
    return std::nullopt;
}

std::vector<domain::Trip> InMemoryTripRepository::findAll() const {
    std::vector<domain::Trip> allTrips;
    for (const auto& pair : trips) {
        allTrips.push_back(pair.second);
    }
    return allTrips;
}

void InMemoryTripRepository::remove(const int& id) {
    trips.erase(id);
}

} // namespace persistence
} // namespace infrastructure
