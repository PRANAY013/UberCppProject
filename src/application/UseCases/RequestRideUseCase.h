#ifndef REQUESTRIDEUSECASE_H
#define REQUESTRIDEUSECASE_H

#include "../../domain/geo/GeoPoint.h"
#include "../../domain/trip/Trip.h"
#include "../../domain/routing/Router.h"
#include "../../domain/trip/Matching.h"
#include <optional>
#include <memory>

class RequestRideUseCase {
public:
    // The use case now depends on the abstract Router interface and the Matching service
    RequestRideUseCase(const Router& router, const Matching& matching);

    std::optional<Trip> execute(int riderId, const GeoPoint& start, const GeoPoint& end);

private:
    const Router& router;
    const Matching& matching;
};

#endif // REQUESTRIDEUSECASE_H
