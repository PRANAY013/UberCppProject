#include "LocalRouterAdapter.h"
#include "../../domain/geo/GeoPoint.h"
#include <iostream>

namespace infrastructure {
namespace routing {

LocalRouterAdapter::LocalRouterAdapter() {} // No longer takes GoogleMapsClient

std::optional<domain::routing::RoutePlan> LocalRouterAdapter::findRoute(const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end) const {
    std::cout << "  [LocalRouterAdapter] Calculating route locally..." << std::endl;

    // Calculate distance using Haversine formula
    double distance = domain::geo::haversineDistance(start, end);

    // Estimate duration based on average speed (e.g., 30 km/h = 8.33 m/s)
    double averageSpeedMps = 30.0 * 1000.0 / 3600.0; // 30 km/h in m/s
    double duration = distance / averageSpeedMps;

    // For simplicity, polyline is empty
    std::string polyline = "";

    std::cout << "  [LocalRouterAdapter] Route calculated: Distance=" << distance << "m, Duration=" << duration << "s" << std::endl;
    return std::make_optional(domain::routing::RoutePlan(polyline, distance, duration));
}

} // namespace routing
} // namespace infrastructure
