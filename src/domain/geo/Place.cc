#include "Place.h"

namespace domain {
namespace geo {

Place::Place(const std::string& name, const GeoPoint& location)
    : name(name), location(location) {}

const std::string& Place::getName() const {
    return name;
}

const GeoPoint& Place::getLocation() const {
    return location;
}

} // namespace geo
} // namespace domain
