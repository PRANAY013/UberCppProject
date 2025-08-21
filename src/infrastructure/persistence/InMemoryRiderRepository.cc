#include "InMemoryRiderRepository.h"

namespace infrastructure {
namespace persistence {

InMemoryRiderRepository::InMemoryRiderRepository() {}

void InMemoryRiderRepository::save(const domain::Rider& rider) {
    riders.insert_or_assign(rider.getId(), rider);
}

std::optional<domain::Rider> InMemoryRiderRepository::findById(const int& id) const {
    auto it = riders.find(id);
    if (it != riders.end()) {
        return it->second;
    }
    return std::nullopt;
}

std::vector<domain::Rider> InMemoryRiderRepository::findAll() const {
    std::vector<domain::Rider> allRiders;
    for (const auto& pair : riders) {
        allRiders.push_back(pair.second);
    }
    return allRiders;
}

void InMemoryRiderRepository::remove(const int& id) {
    riders.erase(id);
}

} // namespace persistence
} // namespace infrastructure
