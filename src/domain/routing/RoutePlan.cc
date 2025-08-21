#include "RoutePlan.h"

namespace domain {
namespace routing {

RoutePlan::RoutePlan(const std::string& polyline, double distance, double duration)
    : polyline(polyline), distance(distance), duration(duration) {}

const std::string& RoutePlan::getPolyline() const {
    return polyline;
}

double RoutePlan::getDistance() const {
    return distance;
}

double RoutePlan::getDuration() const {
    return duration;
}

} // namespace routing
} // namespace domain
