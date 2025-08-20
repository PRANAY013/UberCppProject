#ifndef INMEMORYTRIPREPOSITORY_H
#define INMEMORYTRIPREPOSITORY_H

#include "IRepository.h"
#include "../../domain/trip/Trip.h"
#include <unordered_map>

class InMemoryTripRepository : public IRepository<Trip, int> {
public:
    InMemoryTripRepository();

    void save(const Trip& trip) override;
    std::optional<Trip> findById(const int& id) const override;
    std::vector<Trip> findAll() const override;
    void remove(const int& id) override;

private:
    std::unordered_map<int, Trip> trips;
};

#endif // INMEMORYTRIPREPOSITORY_H
