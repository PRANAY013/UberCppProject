#ifndef MOCKROUTERADAPTER_H
#define MOCKROUTERADAPTER_H

#include "../../domain/routing/Router.h"

class MockRouterAdapter : public Router {
public:
    MockRouterAdapter();

    std::optional<RoutePlan> findRoute(const GeoPoint& start, const GeoPoint& end) const override;
};

#endif // MOCKROUTERADAPTER_H
