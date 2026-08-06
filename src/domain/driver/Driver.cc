#include "Driver.h"

namespace domain {

Driver::Driver(int id, Status status, double rating, const std::string& vehicle, const geo::GeoPoint& location)
    : id(id), status(status), rating(rating), vehicle(vehicle), location_(location) {}

int Driver::getId() const {
    return id;
}

Driver::Status Driver::getStatus() const {
    return status;
}

double Driver::getRating() const {
    return rating;
}

const std::string& Driver::getVehicle() const {
    return vehicle;
}

const geo::GeoPoint& Driver::getLocation() const {
    return location_;
}

void Driver::setLocation(const geo::GeoPoint& loc) {
    location_ = loc;
}

} // namespace domain
