#include "Place.h"

Place::Place(const std::string& name, const GeoPoint& location)
    : name(name), location(location) {}

const std::string& Place::getName() const {
    return name;
}

const GeoPoint& Place::getLocation() const {
    return location;
}
