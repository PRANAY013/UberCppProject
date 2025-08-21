#ifndef ROUTER_H
#define ROUTER_H

#include "../geo/GeoPoint.h"
#include "RoutePlan.h"
#include <optional>

namespace domain {
namespace routing {
class Router {
public:
    virtual ~Router() = default; // Virtual destructor for interface

    // Pure virtual function makes this an interface
    virtual std::optional<routing::RoutePlan> findRoute(const geo::GeoPoint& start, const geo::GeoPoint& end) const = 0;
};
} // namespace routing
} // namespace domain

#endif // ROUTER_H
