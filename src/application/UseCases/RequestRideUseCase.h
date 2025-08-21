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

namespace application {
namespace UseCases {

class RequestRideUseCase {
public:
    RequestRideUseCase(const domain::routing::Router& router, const domain::Matching& matching,
                       infrastructure::persistence::IRepository<domain::Rider, int>& riderRepository,
                       infrastructure::persistence::IRepository<domain::Trip, int>& tripRepository);

    std::optional<domain::Trip> execute(int riderId, const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end);

private:
    const domain::routing::Router& router;
    const domain::Matching& matching;
    infrastructure::persistence::IRepository<domain::Rider, int>& riderRepository;
    infrastructure::persistence::IRepository<domain::Trip, int>& tripRepository;
};

} // namespace UseCases
} // namespace application

#endif // REQUESTRIDEUSECASE_H
