#include <iostream>
#include <vector>
#include <optional>
#include "domain/rider/Rider.h"
#include "domain/rider/RiderHistory.h"
#include "domain/driver/Driver.h"
#include "domain/driver/DriverHistory.h"
#include "domain/trip/Trip.h"
#include "domain/trip/Matching.h"
#include "domain/geo/GeoPoint.h"
#include "domain/geo/GeoFence.h"
#include "domain/geo/Place.h"
#include "domain/pricing/FareCalculator.h"
#include "domain/pricing/SurgeModel.h"

int main() {
    Rider rider(1, 4.5, "No preferences");
    Trip trip(Trip::State::Requested);
    GeoPoint location(40.7128, -74.0060); // New York City

    std::vector<GeoPoint> fenceVertices;
    fenceVertices.push_back(GeoPoint(40.7, -74.1));
    fenceVertices.push_back(GeoPoint(40.8, -74.1));
    fenceVertices.push_back(GeoPoint(40.8, -74.0));
    fenceVertices.push_back(GeoPoint(40.7, -74.0));
    GeoFence zone(fenceVertices);

    Place home("Home", GeoPoint(40.7831, -73.9712)); // Central Park

    FareCalculator fareCalculator;
    SurgeModel surgeModel;

    RiderHistory riderHistory;
    riderHistory.addTrip(trip);

    Driver driver1(Driver::Status::Idle, 4.8, "Toyota Camry");
    Driver driver2(Driver::Status::Idle, 4.9, "Honda Accord");
    std::vector<Driver> availableDrivers = {driver1, driver2};

    DriverHistory driverHistory;
    driverHistory.addTrip(trip);

    Matching matching;
    auto bestDriver = matching.findBestDriver(trip, availableDrivers);


    std::cout << "Rider ID: " << rider.getId() << std::endl;
    std::cout << "Rider Rating: " << rider.getRating() << std::endl;

    std::cout << "Trip State: "  << static_cast<int>(trip.getState()) << std::endl;

    std::cout << "Location: " << location.getLatitude() << ", " << location.getLongitude() << std::endl;
    std::cout << "Is location in zone? " << (zone.contains(location) ? "Yes" : "No") << std::endl;

    std::cout << "Favorite Place: " << home.getName() << " at "
              << home.getLocation().getLatitude() << ", "
              << home.getLocation().getLongitude() << std::endl;

    std::cout << "Estimated Fare: $" << fareCalculator.calculateFare(surgeModel) << std::endl;

    std::cout << "Trips in rider history: " << riderHistory.getTrips().size() << std::endl;
    std::cout << "Trips in driver history: " << driverHistory.getTrips().size() << std::endl;

    if (bestDriver) {
        std::cout << "Best driver found: " << bestDriver->getVehicle() << std::endl;
    } else {
        std::cout << "No suitable driver found." << std::endl;
    }


    return 0;
}
