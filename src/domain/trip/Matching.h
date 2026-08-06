#ifndef MATCHING_H
#define MATCHING_H

#include "../driver/Driver.h"
#include "Trip.h"
#include <vector>
#include <optional>

#include "../geo/GeoPoint.h"

namespace infrastructure { namespace persistence { class InMemoryDriverRepository; } }

namespace domain {
class Matching {
public:
    Matching();

    // Finds the best driver for a given trip.
    std::optional<Driver> findBestDriver(const Trip& trip, const geo::GeoPoint& riderLocation, const infrastructure::persistence::InMemoryDriverRepository& repo) const;
};
} // namespace domain

#endif // MATCHING_H
