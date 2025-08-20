#ifndef INMEMORYDRIVERREPOSITORY_H
#define INMEMORYDRIVERREPOSITORY_H

#include "IRepository.h"
#include "../../domain/driver/Driver.h"
#include <unordered_map>

class InMemoryDriverRepository : public IRepository<Driver, int> {
public:
    InMemoryDriverRepository();

    void save(const Driver& driver) override;
    std::optional<Driver> findById(const int& id) const override;
    std::vector<Driver> findAll() const override;
    void remove(const int& id) override;

private:
    std::unordered_map<int, Driver> drivers;
};

#endif // INMEMORYDRIVERREPOSITORY_H
