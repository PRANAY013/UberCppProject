#include "Driver.h"

Driver::Driver(int id, Status status, double rating, const std::string& vehicle)
    : id(id), status(status), rating(rating), vehicle(vehicle) {}

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
