#ifndef GOOGLEMAPSCLIENT_H
#define GOOGLEMAPSCLIENT_H

#include "../../domain/geo/GeoPoint.h"
#include "../../domain/routing/RoutePlan.h"
#include <string>
#include <optional>
#include <vector>

namespace infrastructure {
namespace http {
class GoogleMapsClient {
public:
    GoogleMapsClient();

    // Placeholder for getting directions.
    // In a real implementation, this would make an HTTP request to Google Maps Directions API.
    std::optional<domain::routing::RoutePlan> getDirections(const domain::geo::GeoPoint& origin, const domain::geo::GeoPoint& destination) const;

    // Placeholder for getting distance matrix.
    // In a real implementation, this would make an HTTP request to Google Maps Distance Matrix API.
    // Returns distance in meters and duration in seconds.
    std::pair<double, double> getDistanceMatrix(const domain::geo::GeoPoint& origin, const domain::geo::GeoPoint& destination) const;

    // Placeholder for getting place details.
    // In a real implementation, this would make an HTTP request to Google Maps Places API.
    std::string getPlaceDetails(const std::string& placeId) const;
};
} // namespace http
} // namespace infrastructure

#endif // GOOGLEMAPSCLIENT_H
