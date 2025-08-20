#include "InMemoryDriverRepository.h"

InMemoryDriverRepository::InMemoryDriverRepository() {}

void InMemoryDriverRepository::save(const Driver& driver) {
    drivers.insert_or_assign(driver.getId(), driver);
}

std::optional<Driver> InMemoryDriverRepository::findById(const int& id) const {
    auto it = drivers.find(id);
    if (it != drivers.end()) {
        return it->second;
    }
    return std::nullopt;
}

std::vector<Driver> InMemoryDriverRepository::findAll() const {
    std::vector<Driver> allDrivers;
    for (const auto& pair : drivers) {
        allDrivers.push_back(pair.second);
    }
    return allDrivers;
}

void InMemoryDriverRepository::remove(const int& id) {
    drivers.erase(id);
}