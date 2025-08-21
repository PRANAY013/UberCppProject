#include "UpdateLocationUseCase.h"
#include <iostream>

namespace application {
namespace UseCases {

UpdateLocationUseCase::UpdateLocationUseCase() {}

void UpdateLocationUseCase::execute(domain::Trip& trip, const domain::geo::GeoPoint& newLocation) {
    // --- Placeholder Implementation ---
    // In a real scenario, this would involve:
    // 1. Updating the trip's location in a persistent storage (repository).
    // 2. Notifying relevant parties (e.g., rider, driver, dispatch).

    trip.setCurrentLocation(newLocation);
    std::cout << "  [UpdateLocationUseCase] Trip location updated to: "
              << newLocation.getLatitude() << ", " << newLocation.getLongitude() << std::endl;
}

} // namespace UseCases
} // namespace application
