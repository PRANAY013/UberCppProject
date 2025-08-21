#ifndef RIDERHISTORY_H
#define RIDERHISTORY_H

#include "../trip/Trip.h"
#include <vector>

namespace domain {
class RiderHistory {
public:
    RiderHistory();

    void addTrip(const Trip& trip);
    const std::vector<Trip>& getTrips() const;

private:
    std::vector<Trip> trips;
};
} // namespace domain

#endif // RIDERHISTORY_H
