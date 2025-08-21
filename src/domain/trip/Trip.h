#ifndef TRIP_H
#define TRIP_H

#include "../geo/GeoPoint.h"
#include "../routing/RoutePlan.h"
#include <optional>

namespace domain {
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

    const geo::GeoPoint& getCurrentLocation() const;
    void setCurrentLocation(const geo::GeoPoint& newLocation);

    const std::optional<routing::RoutePlan>& getRoutePlan() const;
    void setRoutePlan(const routing::RoutePlan& routePlan);

private:
    int id;
    State state;
    geo::GeoPoint currentLocation;
    std::optional<routing::RoutePlan> routePlan_;
};
} // namespace domain

#endif // TRIP_H
