#ifndef ROUTER_H
#define ROUTER_H

#include "../geo/GeoPoint.h"
#include "RoutePlan.h"
#include <optional>

class Router {
public:
    virtual ~Router() = default; // Virtual destructor for interface

    // Pure virtual function makes this an interface
    virtual std::optional<RoutePlan> findRoute(const GeoPoint& start, const GeoPoint& end) const = 0;
};

#endif // ROUTER_H
