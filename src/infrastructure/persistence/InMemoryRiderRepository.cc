#include "InMemoryRiderRepository.h"

InMemoryRiderRepository::InMemoryRiderRepository() {}

void InMemoryRiderRepository::save(const Rider& rider) {
    riders.insert_or_assign(rider.getId(), rider);
}

std::optional<Rider> InMemoryRiderRepository::findById(const int& id) const {
    auto it = riders.find(id);
    if (it != riders.end()) {
        return it->second;
    }
    return std::nullopt;
}

std::vector<Rider> InMemoryRiderRepository::findAll() const {
    std::vector<Rider> allRiders;
    for (const auto& pair : riders) {
        allRiders.push_back(pair.second);
    }
    return allRiders;
}

void InMemoryRiderRepository::remove(const int& id) {
    riders.erase(id);
}
