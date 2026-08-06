#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "../geo/GeoPoint.h"

namespace domain {
class Driver {
public:
    enum class Status {
        Offline,
        Idle,
        Engaged,
        Riding
    };

    Driver(int id, Status status, double rating, const std::string& vehicle, const geo::GeoPoint& location);

    int getId() const;
    Status getStatus() const;
    double getRating() const;
    const std::string& getVehicle() const;
    const geo::GeoPoint& getLocation() const;
    void setLocation(const geo::GeoPoint& loc);

private:
    int id;
    Status status;
    double rating;
    std::string vehicle;
    geo::GeoPoint location_;
};
} // namespace domain

#endif // DRIVER_H
