#include <iostream>
#include "domain/rider/Rider.h"
#include "domain/driver/Driver.h"
#include "domain/trip/Trip.h"

int main() {
    Rider rider(1, 4.5, "No preferences");
    Driver driver(Driver::Status::Idle, 4.8, "Toyota Camry");
    Trip trip(Trip::State::Requested);

    std::cout << "Rider ID: " << rider.getId() << std::endl;
    std::cout << "Rider Rating: " << rider.getRating() << std::endl;

    std::cout << "Driver Status: " << static_cast<int>(driver.getStatus()) << std::endl;
    std::cout << "Driver Vehicle: " << driver.getVehicle() << std::endl;

    std::cout << "Trip State: "  << static_cast<int>(trip.getState()) << std::endl;

    return 0;
}
