#ifndef ROUTEPLAN_H
#define ROUTEPLAN_H

#include "../geo/GeoPoint.h"
#include <vector>
#include <string>

class RoutePlan {
public:
    RoutePlan(const std::string& polyline, double distance, double duration);

    const std::string& getPolyline() const;
    double getDistance() const;
    double getDuration() const;

private:
    std::string polyline;
    double distance; // in meters
    double duration; // in seconds
};

#endif // ROUTEPLAN_H
