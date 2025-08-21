#ifndef GEOPOINT_H
#define GEOPOINT_H

#include <cmath>

namespace domain {
namespace geo {
class GeoPoint {
public:
    GeoPoint(double latitude, double longitude);

    double getLatitude() const;
    double getLongitude() const;

private:
    double latitude;
    double longitude;
};

// Haversine distance function (free function in namespace)
inline double haversineDistance(const GeoPoint& p1, const GeoPoint& p2) {
    const double R = 6371000.0; // Earth's radius in meters

    double lat1Rad = p1.getLatitude() * M_PI / 180.0;
    double lon1Rad = p1.getLongitude() * M_PI / 180.0;
    double lat2Rad = p2.getLatitude() * M_PI / 180.0;
    double lon2Rad = p2.getLongitude() * M_PI / 180.0;

    double dLat = lat2Rad - lat1Rad;
    double dLon = lon2Rad - lon1Rad;

    double a = std::sin(dLat / 2.0) * std::sin(dLat / 2.0) +
               std::cos(lat1Rad) * std::cos(lat2Rad) *
               std::sin(dLon / 2.0) * std::sin(dLon / 2.0);
    double c = 2.0 * std::atan2(std::sqrt(a), std::sqrt(1.0 - a));

    return R * c;
}

} // namespace geo
} // namespace domain

#endif // GEOPOINT_H
