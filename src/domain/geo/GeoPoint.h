#ifndef GEOPOINT_H
#define GEOPOINT_H

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
} // namespace geo
} // namespace domain

#endif // GEOPOINT_H
