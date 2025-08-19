#ifndef GEOFENCE_H
#define GEOFENCE_H

#include "GeoPoint.h"
#include <vector>

class GeoFence {
public:
    GeoFence(const std::vector<GeoPoint>& vertices);

    bool contains(const GeoPoint& point) const;

private:
    std::vector<GeoPoint> vertices;
};

#endif // GEOFENCE_H
