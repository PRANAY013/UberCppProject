#ifndef DRIVER_H
#define DRIVER_H

#include <string>

namespace domain {
class Driver {
public:
    enum class Status {
        Offline,
        Idle,
        Engaged,
        Riding
    };

    Driver(int id, Status status, double rating, const std::string& vehicle);

    int getId() const;
    Status getStatus() const;
    double getRating() const;
    const std::string& getVehicle() const;

private:
    int id;
    Status status;
    double rating;
    std::string vehicle;
};
} // namespace domain

#endif // DRIVER_H
