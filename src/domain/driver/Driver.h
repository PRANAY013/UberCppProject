#ifndef DRIVER_H
#define DRIVER_H

#include <string>

class Driver {
public:
    enum class Status {
        Offline,
        Idle,
        Engaged,
        Riding
    };

    Driver(Status status, double rating, const std::string& vehicle);

    Status getStatus() const;
    double getRating() const;
    const std::string& getVehicle() const;

private:
    Status status;
    double rating;
    std::string vehicle; // Will likely become a Vehicle class later
};

#endif // DRIVER_H
