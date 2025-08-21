#ifndef SHARERIDESTATUSUSECASE_H
#define SHARERIDESTATUSUSECASE_H

#include "../../domain/trip/Trip.h"
#include <string>

namespace application {
namespace UseCases {
class ShareRideStatusUseCase {
public:
    ShareRideStatusUseCase();

    // Shares the current status of a ride.
    // In a real scenario, this would send notifications (SMS, push, email).
    void execute(const domain::Trip& trip, const std::string& recipient = "Rider");
};
} // namespace UseCases
} // namespace application

#endif // SHARERIDESTATUSUSECASE_H
