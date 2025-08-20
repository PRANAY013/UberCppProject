#ifndef INMEMORYRIDERREPOSITORY_H
#define INMEMORYRIDERREPOSITORY_H

#include "IRepository.h"
#include "../../domain/rider/Rider.h"
#include <unordered_map>

class InMemoryRiderRepository : public IRepository<Rider, int> {
public:
    InMemoryRiderRepository();

    void save(const Rider& rider) override;
    std::optional<Rider> findById(const int& id) const override;
    std::vector<Rider> findAll() const override;
    void remove(const int& id) override;

private:
    std::unordered_map<int, Rider> riders;
};

#endif // INMEMORYRIDERREPOSITORY_H
