#include "GeoFence.h"
#include <limits>

namespace domain {
namespace geo {

GeoFence::GeoFence(const std::vector<GeoPoint>& vertices)
    : vertices(vertices) {}

// Ray Casting Algorithm for Point in Polygon
bool GeoFence::contains(const GeoPoint& point) const {
    if (vertices.size() < 3) {
        // A polygon must have at least 3 vertices
        return false;
    }

    bool inside = false;
    double x = point.getLongitude();
    double y = point.getLatitude();

    for (size_t i = 0, j = vertices.size() - 1; i < vertices.size(); j = i++) {
        double xi = vertices[i].getLongitude();
        double yi = vertices[i].getLatitude();
        double xj = vertices[j].getLongitude();
        double yj = vertices[j].getLatitude();

        bool intersect = ((yi > y) != (yj > y))
            && (x < (xj - xi) * (y - yi) / (yj - yi) + xi);
        if (intersect) {
            inside = !inside;
        }
    }

    return inside;
}

} // namespace geo
} // namespace domain

