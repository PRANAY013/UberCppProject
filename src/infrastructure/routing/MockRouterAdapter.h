#ifndef MOCKROUTERADAPTER_H
#define MOCKROUTERADAPTER_H

#include "../../domain/routing/Router.h"

namespace infrastructure {
namespace routing {
class MockRouterAdapter : public domain::routing::Router {
public:
    MockRouterAdapter();

    std::optional<domain::routing::RoutePlan> findRoute(const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end) const override;
};
} // namespace routing
} // namespace infrastructure

#endif // MOCKROUTERADAPTER_H
