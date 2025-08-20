#ifndef SHARERIDESTATUSUSECASE_H
#define SHARERIDESTATUSUSECASE_H

#include "../../domain/trip/Trip.h"
#include <string>

class ShareRideStatusUseCase {
public:
    ShareRideStatusUseCase();

    // Shares the current status of a ride.
    // In a real scenario, this would send notifications (SMS, push, email).
    void execute(const Trip& trip, const std::string& recipient = "Rider");
};

#endif // SHARERIDESTATUSUSECASE_H
