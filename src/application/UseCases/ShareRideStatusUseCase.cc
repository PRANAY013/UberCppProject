#include "ShareRideStatusUseCase.h"
#include <iostream>

namespace application {
namespace UseCases {

ShareRideStatusUseCase::ShareRideStatusUseCase() {}

void ShareRideStatusUseCase::execute(const domain::Trip& trip, const std::string& recipient) {
    // --- Placeholder Implementation ---
    // In a real scenario, this would involve:
    // 1. Formatting the status message.
    // 2. Using an infrastructure service (e.g., a NotificationService) to send the message.

    std::cout << "  [ShareRideStatusUseCase] Sharing status with " << recipient << ":" << std::endl;
    std::cout << "    Trip State: " << static_cast<int>(trip.getState()) << std::endl;
    std::cout << "    Current Location: " << trip.getCurrentLocation().getLatitude() << ", " << trip.getCurrentLocation().getLongitude() << std::endl;
}

} // namespace UseCases
} // namespace application
