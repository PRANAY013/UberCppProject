#include "RideController.h"
#include <iostream>

namespace interfaces {
namespace rest {

RideController::RideController(application::UseCases::RequestRideUseCase& requestRideUseCase)
    : requestRideUseCase(requestRideUseCase) {}

std::string RideController::requestRide(const RideRequestDTO& request) {
    std::cout << "\n  [RideController] Received ride request for Rider ID: " << request.riderId << std::endl;
    std::cout << "    From: (" << request.startLocation.getLatitude() << ", " << request.startLocation.getLongitude() << ")" << std::endl;
    std::cout << "    To: (" << request.endLocation.getLatitude() << ", " << request.endLocation.getLongitude() << ")" << std::endl;

    // Call the application layer use case
    auto trip = requestRideUseCase.execute(request.riderId, request.startLocation, request.endLocation);

    if (trip) {
        std::cout << "  [RideController] Ride request processed successfully. Trip ID: " << trip->getId() << std::endl;
        return "Ride requested successfully. Trip ID: " + std::to_string(trip->getId());
    } else {
        std::cout << "  [RideController] Failed to process ride request." << std::endl;
        return "Failed to request ride.";
    }
}

} // namespace rest
} // namespace interfaces

