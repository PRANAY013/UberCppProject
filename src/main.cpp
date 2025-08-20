#include <iostream>
#include "application/UseCases/RequestRideUseCase.h"
#include "application/UseCases/QuoteFareUseCase.h"
#include "application/UseCases/AssignDriverUseCase.h"
#include "application/UseCases/UpdateLocationUseCase.h"
#include "application/UseCases/ShareRideStatusUseCase.h"
#include "domain/geo/GeoPoint.h"
#include "infrastructure/routing/MockRouterAdapter.h"
#include "domain/trip/Matching.h"
#include "domain/pricing/FareCalculator.h"
#include "domain/pricing/SurgeModel.h"
#include "domain/driver/Driver.h"
#include "infrastructure/persistence/InMemoryRiderRepository.h"
#include "infrastructure/persistence/InMemoryDriverRepository.h"
#include "infrastructure/persistence/InMemoryTripRepository.h"
#include "domain/rider/Rider.h"

int main() {
    std::cout << "Uber C++ Clone" << std::endl;
    std::cout << "----------------" << std::endl;

    // 1. Initialize infrastructure components
    MockRouterAdapter mockRouter;
    InMemoryRiderRepository riderRepository;
    InMemoryDriverRepository driverRepository;
    InMemoryTripRepository tripRepository;

    // Add dummy data to repositories for testing
    Rider dummyRider(1, 4.9, "Standard Preferences");
    riderRepository.save(dummyRider);

    Driver dummyDriver1(101, Driver::Status::Idle, 4.8, "Toyota Camry");
    Driver dummyDriver2(102, Driver::Status::Idle, 4.9, "Honda Accord");
    driverRepository.save(dummyDriver1);
    driverRepository.save(dummyDriver2);


    // 2. Initialize domain services
    Matching matchingService;
    FareCalculator fareCalculator;
    SurgeModel surgeModel;

    // 3. Initialize the application's use cases, injecting dependencies
    RequestRideUseCase requestRideUseCase(mockRouter, matchingService, riderRepository, tripRepository);
    QuoteFareUseCase quoteFareUseCase(fareCalculator, surgeModel);
    AssignDriverUseCase assignDriverUseCase;
    UpdateLocationUseCase updateLocationUseCase;
    ShareRideStatusUseCase shareRideStatusUseCase;

    // 4. Simulate a user requesting a ride
    std::cout << "Requesting a ride from Times Square to Central Park..." << std::endl;
    GeoPoint start(40.7580, -73.9855); // Times Square
    GeoPoint end(40.7831, -73.9712);   // Central Park
    int riderId = 1;

    auto trip = requestRideUseCase.execute(riderId, start, end);

    // 5. Check the result and assign driver if found
    if (trip) {
        std::cout << "Successfully created a trip request!" << std::endl;
        std::cout << "Trip state: " << static_cast<int>(trip->getState()) << std::endl;
        std::cout << "Trip current location: " << trip->getCurrentLocation().getLatitude() << ", " << trip->getCurrentLocation().getLongitude() << std::endl;


        // Simulate finding a driver and assigning them
        assignDriverUseCase.execute(*trip, dummyDriver1);
        std::cout << "Trip state after assignment: " << static_cast<int>(trip->getState()) << std::endl;

        // Simulate location updates
        std::cout << "\nSimulating location updates..." << std::endl;
        updateLocationUseCase.execute(*trip, GeoPoint(40.76, -73.98));
        updateLocationUseCase.execute(*trip, GeoPoint(40.77, -73.975));
        std::cout << "Final trip location: " << trip->getCurrentLocation().getLatitude() << ", " << trip->getCurrentLocation().getLongitude() << std::endl;

        // Share ride status
        std::cout << "\nSharing ride status..." << std::endl;
        shareRideStatusUseCase.execute(*trip);


    } else {
        std::cout << "Failed to create a trip request." << std::endl;
    }

    // 6. Get a fare quote
    std::cout << "\nGetting a fare quote..." << std::endl;
    double estimatedFare = quoteFareUseCase.execute();
    std::cout << "Estimated fare: $" << estimatedFare << std::endl;


    return 0;
}
