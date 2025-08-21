#ifndef INMEMORYTRIPREPOSITORY_H
#define INMEMORYTRIPREPOSITORY_H

#include "IRepository.h"
#include "../../domain/trip/Trip.h"
#include <unordered_map>

namespace infrastructure {
namespace persistence {

class InMemoryTripRepository : public IRepository<domain::Trip, int> {
public:
    InMemoryTripRepository();

    void save(const domain::Trip& trip) override;
    std::optional<domain::Trip> findById(const int& id) const override;
    std::vector<domain::Trip> findAll() const override;
    void remove(const int& id) override;

private:
    std::unordered_map<int, domain::Trip> trips;
};

} // namespace persistence
} // namespace infrastructure

#endif // INMEMORYTRIPREPOSITORY_H
