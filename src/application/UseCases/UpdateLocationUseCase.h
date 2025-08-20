#ifndef UPDATELOCATIONUSECASE_H
#define UPDATELOCATIONUSECASE_H

#include "../../domain/trip/Trip.h"
#include "../../domain/geo/GeoPoint.h"

class UpdateLocationUseCase {
public:
    UpdateLocationUseCase();

    // Updates the current location of a trip.
    // In a real scenario, this would update the trip in a repository.
    void execute(Trip& trip, const GeoPoint& newLocation);
};

#endif // UPDATELOCATIONUSECASE_H
