#include "Trip.h"
#include "../geo/GeoPoint.h"
#include "../routing/RoutePlan.h"

namespace domain {

Trip::Trip(int id, State state)
    : id(id), state(state), currentLocation(geo::GeoPoint(0.0, 0.0)), routePlan_(std::nullopt) {}

int Trip::getId() const {
    return id;
}

Trip::State Trip::getState() const {
    return state;
}

void Trip::setState(State newState) {
    state = newState;
}

const geo::GeoPoint& Trip::getCurrentLocation() const {
    return currentLocation;
}

void Trip::setCurrentLocation(const geo::GeoPoint& newLocation) {
    currentLocation = newLocation;
}

const std::optional<routing::RoutePlan>& Trip::getRoutePlan() const {
    return routePlan_;
}

void Trip::setRoutePlan(const routing::RoutePlan& routePlan) {
    routePlan_ = routePlan;
}

} // namespace domain
