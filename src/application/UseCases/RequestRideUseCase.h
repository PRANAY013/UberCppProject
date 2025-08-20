#ifndef REQUESTRIDEUSECASE_H
#define REQUESTRIDEUSECASE_H

#include "../../domain/geo/GeoPoint.h"
#include "../../domain/trip/Trip.h"
#include "../../domain/routing/Router.h"
#include "../../domain/trip/Matching.h"
#include "../../infrastructure/persistence/IRepository.h"
#include "../../domain/rider/Rider.h"
#include "../../domain/driver/Driver.h"

#include <optional>
#include <memory>

class RequestRideUseCase {
public:
    // The use case now depends on the abstract Router interface, the Matching service,
    // and repositories for Rider and Trip.
    RequestRideUseCase(const Router& router, const Matching& matching,
                       IRepository<Rider, int>& riderRepository,
                       IRepository<Trip, int>& tripRepository);

    std::optional<Trip> execute(int riderId, const GeoPoint& start, const GeoPoint& end);

private:
    const Router& router;
    const Matching& matching;
    IRepository<Rider, int>& riderRepository;
    IRepository<Trip, int>& tripRepository;
};

#endif // REQUESTRIDEUSECASE_H
