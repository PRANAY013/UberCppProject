#include "DriverHistory.h"

DriverHistory::DriverHistory() {}

void DriverHistory::addTrip(const Trip& trip) {
    trips.push_back(trip);
}

const std::vector<Trip>& DriverHistory::getTrips() const {
    return trips;
}
