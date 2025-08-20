#include "MockRouterAdapter.h"

MockRouterAdapter::MockRouterAdapter() {}

std::optional<RoutePlan> MockRouterAdapter::findRoute(const GeoPoint& start, const GeoPoint& end) const {
    // This is a mock implementation. It does not call a real routing service.
    // It returns a fixed route plan for testing purposes.
    std::string mockPolyline = "gfo}F`a}uM..."; // A dummy polyline
    double mockDistance = 5000.0; // 5km
    double mockDuration = 600.0;  // 10 minutes

    return RoutePlan(mockPolyline, mockDistance, mockDuration);
}
