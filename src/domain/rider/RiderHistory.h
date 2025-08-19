#ifndef RIDERHISTORY_H
#define RIDERHISTORY_H

#include "../trip/Trip.h"
#include <vector>

class RiderHistory {
public:
    RiderHistory();

    void addTrip(const Trip& trip);
    const std::vector<Trip>& getTrips() const;

private:
    std::vector<Trip> trips;
};

#endif // RIDERHISTORY_H
