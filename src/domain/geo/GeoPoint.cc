#include "GeoPoint.h"

namespace domain {
namespace geo {

GeoPoint::GeoPoint(double latitude, double longitude)
    : latitude(latitude), longitude(longitude) {}

double GeoPoint::getLatitude() const {
    return latitude;
}

double GeoPoint::getLongitude() const {
    return longitude;
}

} // namespace geo
} // namespace domain
