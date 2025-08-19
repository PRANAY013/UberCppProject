#ifndef GEOPOINT_H
#define GEOPOINT_H

class GeoPoint {
public:
    GeoPoint(double latitude, double longitude);

    double getLatitude() const;
    double getLongitude() const;

private:
    double latitude;
    double longitude;
};

#endif // GEOPOINT_H
