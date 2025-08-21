#include "AssignDriverUseCase.h"
#include <iostream>

namespace application {
namespace UseCases {

AssignDriverUseCase::AssignDriverUseCase() {}

void AssignDriverUseCase::execute(domain::Trip& trip, const domain::Driver& driver) {
    // --- Placeholder Implementation ---
    // In a real scenario, this would involve:
    // 1. Updating the trip's state in a persistent storage (repository).
    // 2. Updating the driver's status (e.g., to Engaged) in a persistent storage.
    // 3. Notifying the rider and driver.

    trip.setState(domain::Trip::State::Assigned); // Update the trip state
    std::cout << "  [AssignDriverUseCase] Driver " << driver.getVehicle() << " assigned to trip. Trip state updated to Assigned." << std::endl;
}

} // namespace UseCases
} // namespace application
