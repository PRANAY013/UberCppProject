#include "Matching.h"

Matching::Matching() {}

// Finds the best driver for a given trip from a list of available drivers.
// Returns an optional Driver, which will be empty if no suitable driver is found.
std::optional<Driver> Matching::findBestDriver(const Trip& trip, const std::vector<Driver>& availableDrivers) const {
    // --- Placeholder Implementation ---
    // This is a naive implementation for demonstration purposes.
    // The intention is for this method to eventually contain a sophisticated
    // matching algorithm. This could involve:
    //   - Calculating the distance between the trip's origin and each driver.
    //   - Factoring in driver rating, vehicle type, and driver preferences.
    //   - Using the 'routing' module to get an accurate ETA for each driver.

    if (availableDrivers.empty()) {
        return std::nullopt; // No drivers available
    }

    // For now, we simply return the first driver in the list.
    return availableDrivers.front();
}
