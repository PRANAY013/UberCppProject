#include <iostream>
#include "application/UseCases/RequestRideUseCase.h"
#include "application/UseCases/QuoteFareUseCase.h"
#include "application/UseCases/AssignDriverUseCase.h"
#include "application/UseCases/UpdateLocationUseCase.h"
#include "application/UseCases/ShareRideStatusUseCase.h"
#include "domain/geo/GeoPoint.h"
#include "infrastructure/routing/MockRouterAdapter.h"
#include "infrastructure/routing/GoogleRouterAdapter.h"
#include "domain/trip/Matching.h"
#include "domain/pricing/FareCalculator.h"
#include "domain/pricing/SurgeModel.h"
#include "domain/driver/Driver.h"
#include "infrastructure/persistence/InMemoryRiderRepository.h"
#include "infrastructure/persistence/InMemoryDriverRepository.h"
#include "infrastructure/persistence/InMemoryTripRepository.h"
#include "infrastructure/http/GoogleMapsClient.h"
#include "infrastructure/messaging/EventBus.h"
#include "infrastructure/payments/PaymentsGateway.h"
#include "interfaces/rest/RideController.h"
#include "interfaces/rest/RideRequestDTO.h"
#include "domain/rider/Rider.h"

// Define a custom event (still needed for EventBus demo)
class TripCreatedEvent : public infrastructure::messaging::Event {
public:
    TripCreatedEvent(int tripId) : tripId_(tripId) {}
    int getTripId() const { return tripId_; }
private:
    int tripId_;
};

int main() {
    std::cout << "Uber C++ Clone" << std::endl;
    std::cout << "----------------" << std::endl;

    // 1. Initialize infrastructure components
    infrastructure::routing::MockRouterAdapter mockRouter;
    infrastructure::http::GoogleMapsClient googleMapsClient;
    infrastructure::routing::GoogleRouterAdapter googleRouter(googleMapsClient);
    infrastructure::persistence::InMemoryRiderRepository riderRepository;
    infrastructure::persistence::InMemoryDriverRepository driverRepository;
    infrastructure::persistence::InMemoryTripRepository tripRepository;
    infrastructure::messaging::EventBus eventBus;
    infrastructure::payments::PaymentsGateway paymentsGateway;

    // Add dummy data to repositories for testing
    domain::Rider dummyRider(1, 4.9, "Standard Preferences");
    riderRepository.save(dummyRider);

    domain::Driver dummyDriver1(101, domain::Driver::Status::Idle, 4.8, "Toyota Camry");
    domain::Driver dummyDriver2(102, domain::Driver::Status::Idle, 4.9, "Honda Accord");
    driverRepository.save(dummyDriver1);
    driverRepository.save(dummyDriver2);

    // Subscribe to TripCreatedEvent
    eventBus.subscribe<TripCreatedEvent>([](const TripCreatedEvent& event) {
        std::cout << "  [EventBus] TripCreatedEvent received for Trip ID: " << event.getTripId() << std::endl;
        // In a real application, a notification service or billing service might react here.
    });


    // 2. Initialize domain services
    domain::Matching matchingService;
    domain::pricing::FareCalculator fareCalculator;
    domain::pricing::SurgeModel surgeModel;

    // 3. Initialize the application's use cases, injecting dependencies
    application::UseCases::RequestRideUseCase requestRideUseCase(googleRouter, matchingService, riderRepository, tripRepository);
    application::UseCases::QuoteFareUseCase quoteFareUseCase(fareCalculator, surgeModel);
    application::UseCases::AssignDriverUseCase assignDriverUseCase;
    application::UseCases::UpdateLocationUseCase updateLocationUseCase;
    application::UseCases::ShareRideStatusUseCase shareRideStatusUseCase;

    // 4. Initialize Interfaces (Controllers)
    interfaces::rest::RideController rideController(requestRideUseCase);

    // 5. Simulate an API call to the RideController
    std::cout << "\nSimulating API call to RideController..." << std::endl;
    interfaces::rest::RideRequestDTO rideRequest;
    rideRequest.riderId = 1;
    rideRequest.startLocation = domain::geo::GeoPoint(40.7580, -73.9855); // Times Square
    rideRequest.endLocation = domain::geo::GeoPoint(40.7831, -73.9712);   // Central Park

    std::string controllerResponse = rideController.requestRide(rideRequest);
    std::cout << "  Controller Response: " << controllerResponse << std::endl;

    // The rest of the main.cpp content is for demonstrating individual components
    // and would typically be replaced by actual application flow driven by controllers.

    // 6. Get a fare quote (demonstration)
    std::cout << "\nGetting a fare quote (demonstration)..." << std::endl;
    double estimatedFare = quoteFareUseCase.execute();
    std::cout << "Estimated fare: $" << estimatedFare << std::endl;

    // 7. Demonstrate GoogleMapsClient (demonstration)
    std::cout << "\nDemonstrating GoogleMapsClient (demonstration)..." << std::endl;
    domain::geo::GeoPoint start(40.7580, -73.9855); // Times Square
    domain::geo::GeoPoint end(40.7831, -73.9712);   // Central Park
    auto directions = googleMapsClient.getDirections(start, end);
    if (directions) {
        std::cout << "  Directions found: Distance=" << directions->getDistance() << "m, Duration=" << directions->getDuration() << "s" << std::endl;
    }
    auto distanceMatrix = googleMapsClient.getDistanceMatrix(start, end);
    std::cout << "  Distance Matrix: Distance=" << distanceMatrix.first << "m, Duration=" << distanceMatrix.second << "s" << std::endl;
    std::cout << "  Place Details: " << googleMapsClient.getPlaceDetails("ChIJd8PN8_xYwokR_g_g_g_g_g") << std::endl;

    // 8. Demonstrate PaymentsGateway (demonstration)
    std::cout << "\nDemonstrating PaymentsGateway (demonstration)..." << std::endl;
    bool paymentSuccess = paymentsGateway.processPayment("user123", 18.6, "Credit Card");
    std::cout << "  Payment processed: " << (paymentSuccess ? "Success" : "Failure") << std::endl;
    bool refundSuccess = paymentsGateway.refund("txn_abc123", 5.0);
    std::cout << "  Refund processed: " << (refundSuccess ? "Success" : "Failure") << std::endl;


    return 0;
}
