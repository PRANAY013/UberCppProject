#ifndef DRIVERHISTORY_H
#define DRIVERHISTORY_H

#include "../trip/Trip.h"
#include <vector>

namespace domain {
class DriverHistory {
public:
    DriverHistory();

    void addTrip(const Trip& trip);
    const std::vector<Trip>& getTrips() const;

private:
    std::vector<Trip> trips;
};
} // namespace domain

#endif // DRIVERHISTORY_H
