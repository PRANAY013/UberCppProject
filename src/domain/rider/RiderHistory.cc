#include "RiderHistory.h"

namespace domain {

RiderHistory::RiderHistory() {}

void RiderHistory::addTrip(const Trip& trip) {
    trips.push_back(trip);
}

const std::vector<Trip>& RiderHistory::getTrips() const {
    return trips;
}

} // namespace domain
