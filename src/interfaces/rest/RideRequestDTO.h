#ifndef RIDEREQUESTDTO_H
#define RIDEREQUESTDTO_H

#include "../../domain/geo/GeoPoint.h"
#include <string>

namespace interfaces {
namespace rest {

// Data Transfer Object for a ride request
struct RideRequestDTO {
    int riderId;
    domain::geo::GeoPoint startLocation;
    domain::geo::GeoPoint endLocation;
    // Add other fields as needed, e.g., paymentMethod, preferences

    // Constructor to allow initialization
    RideRequestDTO(int id = 0, const domain::geo::GeoPoint& start = domain::geo::GeoPoint(0,0), const domain::geo::GeoPoint& end = domain::geo::GeoPoint(0,0))
        : riderId(id), startLocation(start), endLocation(end) {}
};

} // namespace rest
} // namespace interfaces

#endif // RIDEREQUESTDTO_H