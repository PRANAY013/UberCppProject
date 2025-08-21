#ifndef GOOGLEROUTERADAPTER_H
#define GOOGLEROUTERADAPTER_H

#include "../../domain/routing/Router.h"
#include "../http/GoogleMapsClient.h"

namespace infrastructure {
namespace routing {
class GoogleRouterAdapter : public domain::routing::Router {
public:
    GoogleRouterAdapter(const http::GoogleMapsClient& client);

    std::optional<domain::routing::RoutePlan> findRoute(const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end) const override;

private:
    const http::GoogleMapsClient& client;
};
} // namespace routing
} // namespace infrastructure

#endif // GOOGLEROUTERADAPTER_H
