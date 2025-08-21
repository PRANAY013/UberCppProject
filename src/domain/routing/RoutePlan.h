#ifndef ROUTEPLAN_H
#define ROUTEPLAN_H

#include "../geo/GeoPoint.h"
#include <vector>
#include <string>

namespace domain {
namespace routing {
class RoutePlan {
public:
    RoutePlan(const std::string& polyline, double distance, double duration);

    const std::string& getPolyline() const;
    double getDistance() const;
    double getDuration() const;

private:
    std::string polyline;
    double distance; // in meters
    double duration; // in seconds
};
} // namespace routing
} // namespace domain

#endif // ROUTEPLAN_H
