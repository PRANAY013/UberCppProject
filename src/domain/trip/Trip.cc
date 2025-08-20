#include "Trip.h"
#include "../geo/GeoPoint.h"

Trip::Trip(int id, State state)
    : id(id), state(state), currentLocation(0.0, 0.0) {}

int Trip::getId() const {
    return id;
}

Trip::State Trip::getState() const {
    return state;
}

void Trip::setState(State newState) {
    state = newState;
}

const GeoPoint& Trip::getCurrentLocation() const {
    return currentLocation;
}

void Trip::setCurrentLocation(const GeoPoint& newLocation) {
    currentLocation = newLocation;
}
