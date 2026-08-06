#include "Matching.h"
#include "../../infrastructure/persistence/InMemoryDriverRepository.h"

namespace domain {

Matching::Matching() {}

std::optional<Driver> Matching::findBestDriver(const Trip& trip, const geo::GeoPoint& riderLocation, const infrastructure::persistence::InMemoryDriverRepository& repo) const {
    auto nearby_drivers = repo.findNearestInRadius(riderLocation, 5.0);
    std::optional<Driver> best_driver;
    double max_rating = -1.0;

    for (const auto& d : nearby_drivers) {
        if (d.getStatus() == Driver::Status::Idle && d.getRating() > max_rating) {
            max_rating = d.getRating();
            best_driver = d;
        }
    }
    return best_driver;
}

} // namespace domain
