#ifndef GEOFENCE_H
#define GEOFENCE_H

#include "GeoPoint.h"
#include <vector>

namespace domain {
namespace geo {
class GeoFence {
public:
    GeoFence(const std::vector<GeoPoint>& vertices);

    bool contains(const GeoPoint& point) const;

private:
    std::vector<GeoPoint> vertices;
};
} // namespace geo
} // namespace domain

#endif // GEOFENCE_H
