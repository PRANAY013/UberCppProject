#include "GeoFence.h"

GeoFence::GeoFence(const std::vector<GeoPoint>& vertices)
    : vertices(vertices) {}

bool GeoFence::contains(const GeoPoint& point) const {
    // Placeholder implementation. A real implementation would use an algorithm
    // like ray casting to determine if the point is inside the polygon.
    return true;
}
