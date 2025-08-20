#include "RequestRideUseCase.h"
#include "../../domain/trip/Trip.h"
#include "../../domain/routing/RoutePlan.h"
#include "../../domain/driver/Driver.h"
#include <vector>
#include <iostream>

RequestRideUseCase::RequestRideUseCase(const Router& router, const Matching& matching)
    : router(router), matching(matching) {}

std::optional<Trip> RequestRideUseCase::execute(int riderId, const GeoPoint& start, const GeoPoint& end) {
    // --- Placeholder Implementation ---
    // 1. Fetch Rider from repository (not implemented yet)
    // 2. Create a new Trip object
    // 3. Save the new Trip to a repository
    // 4. Find a driver using the Matching service
    // 5. Assign driver to trip
    // 6. Return the updated trip

    // For now, we'll just create a trip and return it.
    Trip newTrip(Trip::State::Requested);
    // In the future, the trip would be initialized with more data,
    // like riderId, start, and end points.

    // Use the injected router to find a route
    auto routePlan = router.findRoute(start, end);
    if (routePlan) {
        std::cout << "  [RequestRideUseCase] Route found! Distance: " << routePlan->getDistance() << "m, Duration: " << routePlan->getDuration() << "s" << std::endl;
        // In a real scenario, we would associate this route with the trip
    } else {
        std::cout << "  [RequestRideUseCase] No route found." << std::endl;
    }

    // Use the injected matching service to find a driver
    // For demonstration, create some dummy drivers
    Driver driver1(Driver::Status::Idle, 4.8, "Toyota Camry");
    Driver driver2(Driver::Status::Idle, 4.9, "Honda Accord");
    std::vector<Driver> availableDrivers = {driver1, driver2};

    auto bestDriver = matching.findBestDriver(newTrip, availableDrivers);

    if (bestDriver) {
        std::cout << "  [RequestRideUseCase] Best driver found: " << bestDriver->getVehicle() << std::endl;
        // In a real scenario, we would assign this driver to the trip
        newTrip = Trip(Trip::State::Assigned); // Update trip state to assigned
    } else {
        std::cout << "  [RequestRideUseCase] No suitable driver found." << std::endl;
    }

    return newTrip;
}
