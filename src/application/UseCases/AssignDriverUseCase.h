#ifndef ASSIGNDRIVERUSECASE_H
#define ASSIGNDRIVERUSECASE_H

#include "../../domain/trip/Trip.h"
#include "../../domain/driver/Driver.h"

class AssignDriverUseCase {
public:
    AssignDriverUseCase();

    // Assigns a driver to a trip.
    // In a real scenario, this would update the trip in a repository
    // and potentially update the driver's status.
    void execute(Trip& trip, const Driver& driver);
};

#endif // ASSIGNDRIVERUSECASE_H
