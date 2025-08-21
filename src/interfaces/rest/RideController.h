#ifndef RIDECONTROLLER_H
#define RIDECONTROLLER_H

#include "../rest/RideRequestDTO.h"
#include "../../application/UseCases/RequestRideUseCase.h"
#include <string>

namespace interfaces {
namespace rest {

class RideController {
public:
    // Controller takes use cases as dependencies
    RideController(application::UseCases::RequestRideUseCase& requestRideUseCase);

    // Simulates a REST endpoint for requesting a ride
    std::string requestRide(const RideRequestDTO& request);

private:
    application::UseCases::RequestRideUseCase& requestRideUseCase;
};

} // namespace rest
} // namespace interfaces

#endif // RIDECONTROLLER_H
