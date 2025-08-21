#ifndef UPDATELOCATIONUSECASE_H
#define UPDATELOCATIONUSECASE_H

#include "../../domain/trip/Trip.h"
#include "../../domain/geo/GeoPoint.h"

namespace application {
namespace UseCases {
class UpdateLocationUseCase {
public:
    UpdateLocationUseCase();

    // Updates the current location of a trip.
    // In a real scenario, this would update the trip in a repository.
    void execute(domain::Trip& trip, const domain::geo::GeoPoint& newLocation);
};
} // namespace UseCases
} // namespace application

#endif // UPDATELOCATIONUSECASE_H
