#include <iostream>
#include "application/UseCases/RequestRideUseCase.h"
#include "application/UseCases/QuoteFareUseCase.h"
#include "application/UseCases/AssignDriverUseCase.h"
#include "domain/geo/GeoPoint.h"
#include "infrastructure/routing/MockRouterAdapter.h"
#include "domain/trip/Matching.h"
#include "domain/pricing/FareCalculator.h"
#include "domain/pricing/SurgeModel.h"
#include "domain/driver/Driver.h"

int main() {
    std::cout << "Uber C++ Clone" << std::endl;
    std::cout << "----------------" << std::endl;

    // 1. Initialize infrastructure components
    MockRouterAdapter mockRouter;

    // 2. Initialize domain services
    Matching matchingService;
    FareCalculator fareCalculator;
    SurgeModel surgeModel;

    // 3. Initialize the application's use cases, injecting dependencies
    RequestRideUseCase requestRideUseCase(mockRouter, matchingService);
    QuoteFareUseCase quoteFareUseCase(fareCalculator, surgeModel);
    AssignDriverUseCase assignDriverUseCase;

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

        // Simulate finding a driver and assigning them
        Driver dummyDriver(Driver::Status::Idle, 4.8, "Simulated Driver Vehicle");
        assignDriverUseCase.execute(*trip, dummyDriver);
        std::cout << "Trip state after assignment: " << static_cast<int>(trip->getState()) << std::endl;

    } else {
        std::cout << "Failed to create a trip request." << std::endl;
    }

    // 6. Get a fare quote
    std::cout << "\nGetting a fare quote..." << std::endl;
    double estimatedFare = quoteFareUseCase.execute();
    std::cout << "Estimated fare: $" << estimatedFare << std::endl;


    return 0;
}
