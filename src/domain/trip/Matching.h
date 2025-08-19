#ifndef MATCHING_H
#define MATCHING_H

#include "../driver/Driver.h"
#include "Trip.h"
#include <vector>
#include <optional>

class Matching {
public:
    Matching();

    // Finds the best driver for a given trip from a list of available drivers.
    // Returns an optional Driver, which will be empty if no suitable driver is found.
    std::optional<Driver> findBestDriver(const Trip& trip, const std::vector<Driver>& availableDrivers) const;
};

#endif // MATCHING_H
