#include "RequestRideUseCase.h"
#include "../../domain/trip/Trip.h"
#include "../../domain/routing/RoutePlan.h"
#include "../../domain/driver/Driver.h"
#include "../../domain/rider/Rider.h"
#include <vector>
#include <iostream>

namespace application {
namespace UseCases {

// Static counter for generating unique Trip IDs
static int nextTripId = 1;

RequestRideUseCase::RequestRideUseCase(const domain::routing::Router& router, const domain::Matching& matching,
                                       infrastructure::persistence::IRepository<domain::Rider, int>& riderRepository,
                                       infrastructure::persistence::IRepository<domain::Trip, int>& tripRepository)
    : router(router), matching(matching), riderRepository(riderRepository), tripRepository(tripRepository) {}

std::optional<domain::Trip> RequestRideUseCase::execute(int riderId, const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end) {
    // --- Placeholder Implementation ---
    // 1. Fetch Rider from repository
    auto rider = riderRepository.findById(riderId);
    if (!rider) {
        std::cout << "  [RequestRideUseCase] Rider with ID " << riderId << " not found." << std::endl;
        return std::nullopt; // Rider not found
    }
    std::cout << "  [RequestRideUseCase] Rider " << rider->getId() << " fetched from repository." << std::endl;


    // 2. Create a new Trip object
    domain::Trip newTrip(nextTripId++, domain::Trip::State::Requested); // Assign unique ID
    // In the future, the trip would be initialized with more data,
    // like riderId, start, and end points.

    // 3. Save the new Trip to a repository
    tripRepository.save(newTrip);
    std::cout << "  [RequestRideUseCase] Trip " << newTrip.getId() << " saved to repository." << std::endl;


    // 4. Use the injected router to find a route
    auto routePlan = router.findRoute(start, end);
    if (routePlan) {
        std::cout << "  [RequestRideUseCase] Route found! Distance: " << routePlan->getDistance() << "m, Duration: " << routePlan->getDuration() << "s" << std::endl;
        newTrip.setRoutePlan(*routePlan); // Set the route plan on the trip
    } else {
        std::cout << "  [RequestRideUseCase] No route found." << std::endl;
    }

    // 5. Use the injected matching service to find a driver
    // For demonstration, create some dummy drivers
    domain::Driver driver1(101, domain::Driver::Status::Idle, 4.8, "Toyota Camry"); // Assign ID to dummy driver
    domain::Driver driver2(102, domain::Driver::Status::Idle, 4.9, "Honda Accord"); // Assign ID to dummy driver
    std::vector<domain::Driver> availableDrivers = {driver1, driver2};

    auto bestDriver = matching.findBestDriver(newTrip, availableDrivers);

    if (bestDriver) {
        std::cout << "  [RequestRideUseCase] Best driver found: " << bestDriver->getVehicle() << std::endl;
        // In a real scenario, we would assign this driver to the trip
        newTrip.setState(domain::Trip::State::Assigned); // Update trip state to assigned
        // We also need to save the updated trip back to the repository
        tripRepository.save(newTrip);
    } else {
        std::cout << "  [RequestRideUseCase] No suitable driver found." << std::endl;
    }

    return std::make_optional(newTrip);
}

} // namespace UseCases
} // namespace application