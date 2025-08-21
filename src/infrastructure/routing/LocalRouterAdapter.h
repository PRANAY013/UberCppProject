#ifndef LOCALROUTERADAPTER_H
#define LOCALROUTERADAPTER_H

#include "../../domain/routing/Router.h"
#include "../../domain/geo/GeoPoint.h"
#include <optional>

namespace infrastructure {
namespace routing {

class LocalRouterAdapter : public domain::routing::Router {
public:
    LocalRouterAdapter(); // No longer takes GoogleMapsClient

    std::optional<domain::routing::RoutePlan> findRoute(const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end) const override;
};

} // namespace routing
} // namespace infrastructure

#endif // LOCALROUTERADAPTER_H
