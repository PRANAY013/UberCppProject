#ifndef INMEMORYDRIVERREPOSITORY_H
#define INMEMORYDRIVERREPOSITORY_H

#include "IRepository.h"
#include "../../domain/driver/Driver.h"
#include "../../domain/geo/SpatialGrid.h"
#include <unordered_map>
#include <shared_mutex>

namespace infrastructure {
namespace persistence {

class InMemoryDriverRepository : public IRepository<domain::Driver, int> {
public:
    InMemoryDriverRepository();

    void save(const domain::Driver& driver) override;
    std::optional<domain::Driver> findById(const int& id) const override;
    std::vector<domain::Driver> findAll() const override;
    void remove(const int& id) override;

    // NEW spatial API
    std::vector<domain::Driver> findNearestInRadius(
        const domain::geo::GeoPoint& center, double radius_km) const;
    void updateDriverLocation(int driver_id, const domain::geo::GeoPoint& new_loc);

private:
    mutable std::shared_mutex               rw_mutex_;
    std::unordered_map<int, domain::Driver> drivers_;  // renamed from 'drivers'
    domain::geo::SpatialGrid                spatial_grid_;
};

} // namespace persistence
} // namespace infrastructure

#endif // INMEMORYDRIVERREPOSITORY_H
