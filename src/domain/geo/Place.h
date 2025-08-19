#ifndef PLACE_H
#define PLACE_H

#include "GeoPoint.h"
#include <string>

class Place {
public:
    Place(const std::string& name, const GeoPoint& location);

    const std::string& getName() const;
    const GeoPoint& getLocation() const;

private:
    std::string name;
    GeoPoint location;
};

#endif // PLACE_H
