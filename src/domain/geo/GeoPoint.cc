#include "GeoPoint.h"

GeoPoint::GeoPoint(double latitude, double longitude)
    : latitude(latitude), longitude(longitude) {}

double GeoPoint::getLatitude() const {
    return latitude;
}

double GeoPoint::getLongitude() const {
    return longitude;
}
