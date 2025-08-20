#ifndef TRIP_H
#define TRIP_H

#include "../geo/GeoPoint.h"

class Trip {
public:
    enum class State {
        Requested,
        Assigned,
        Enroute,
        Pickup,
        InRide,
        Completed,
        Canceled
    };

    Trip(int id, State state);

    int getId() const;
    State getState() const;
    void setState(State newState);

    const GeoPoint& getCurrentLocation() const;
    void setCurrentLocation(const GeoPoint& newLocation);

private:
    int id;
    State state;
    GeoPoint currentLocation;
};

#endif // TRIP_H
