#include "MockRouterAdapter.h"

namespace infrastructure {
namespace routing {

MockRouterAdapter::MockRouterAdapter() {}

std::optional<domain::routing::RoutePlan> MockRouterAdapter::findRoute(const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end) const {
    // This is a mock implementation. It does not call a real routing service.
    // It returns a fixed route plan for testing purposes.
    std::string mockPolyline = "gfo}F`a}uM..."; // A dummy polyline
    double mockDistance = 5000.0; // 5km
    double mockDuration = 600.0;  // 10 minutes

    return domain::routing::RoutePlan(mockPolyline, mockDistance, mockDuration);
}

} // namespace routing
} // namespace infrastructure
