#include "Driver.h"

Driver::Driver(Status status, double rating, const std::string& vehicle)
    : status(status), rating(rating), vehicle(vehicle) {}

Driver::Status Driver::getStatus() const {
    return status;
}

double Driver::getRating() const {
    return rating;
}

const std::string& Driver::getVehicle() const {
    return vehicle;
}
