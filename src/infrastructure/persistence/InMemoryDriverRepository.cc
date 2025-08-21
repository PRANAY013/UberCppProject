#include "InMemoryDriverRepository.h"

namespace infrastructure {
namespace persistence {

InMemoryDriverRepository::InMemoryDriverRepository() {}

void InMemoryDriverRepository::save(const domain::Driver& driver) {
    drivers.insert_or_assign(driver.getId(), driver);
}

std::optional<domain::Driver> InMemoryDriverRepository::findById(const int& id) const {
    auto it = drivers.find(id);
    if (it != drivers.end()) {
        return it->second;
    }
    return std::nullopt;
}

std::vector<domain::Driver> InMemoryDriverRepository::findAll() const {
    std::vector<domain::Driver> allDrivers;
    for (const auto& pair : drivers) {
        allDrivers.push_back(pair.second);
    }
    return allDrivers;
}

void InMemoryDriverRepository::remove(const int& id) {
    drivers.erase(id);
}

} // namespace persistence
} // namespace infrastructure
