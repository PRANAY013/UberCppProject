#ifndef DRIVERHISTORY_H
#define DRIVERHISTORY_H

#include "../trip/Trip.h"
#include <vector>

class DriverHistory {
public:
    DriverHistory();

    void addTrip(const Trip& trip);
    const std::vector<Trip>& getTrips() const;

private:
    std::vector<Trip> trips;
};

#endif // DRIVERHISTORY_H
