#include "InMemoryTripRepository.h"

InMemoryTripRepository::InMemoryTripRepository() {}

void InMemoryTripRepository::save(const Trip& trip) {
    trips.insert_or_assign(trip.getId(), trip);
}

std::optional<Trip> InMemoryTripRepository::findById(const int& id) const {
    auto it = trips.find(id);
    if (it != trips.end()) {
        return it->second;
    }
    return std::nullopt;
}

std::vector<Trip> InMemoryTripRepository::findAll() const {
    std::vector<Trip> allTrips;
    for (const auto& pair : trips) {
        allTrips.push_back(pair.second);
    }
    return allTrips;
}

void InMemoryTripRepository::remove(const int& id) {
    trips.erase(id);
}
