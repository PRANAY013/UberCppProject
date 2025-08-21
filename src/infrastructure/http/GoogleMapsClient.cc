#include "GoogleMapsClient.h"
#include <iostream>

namespace infrastructure {
namespace http {

GoogleMapsClient::GoogleMapsClient() {}

std::optional<domain::routing::RoutePlan> GoogleMapsClient::getDirections(const domain::geo::GeoPoint& origin, const domain::geo::GeoPoint& destination) const {
    std::cout << "  [GoogleMapsClient] Getting directions from (" << origin.getLatitude() << ", " << origin.getLongitude() << ") to ("
              << destination.getLatitude() << ", " << destination.getLongitude() << ")..." << std::endl;
    // Mock implementation: return a fixed route plan
    return std::make_optional(domain::routing::RoutePlan("mock_polyline_directions", 10000.0, 1200.0)); // 10km, 20min
}

std::pair<double, double> GoogleMapsClient::getDistanceMatrix(const domain::geo::GeoPoint& origin, const domain::geo::GeoPoint& destination) const {
    std::cout << "  [GoogleMapsClient] Getting distance matrix from (" << origin.getLatitude() << ", " << origin.getLongitude() << ") to ("
              << destination.getLatitude() << ", " << destination.getLongitude() << ")..." << std::endl;
    // Mock implementation: return fixed distance and duration
    return {5000.0, 600.0}; // 5km, 10min
}

std::string GoogleMapsClient::getPlaceDetails(const std::string& placeId) const {
    std::cout << "  [GoogleMapsClient] Getting details for place ID: " << placeId << "..." << std::endl;
    // Mock implementation
    return "Mock Place Details for " + placeId;
}

} // namespace http
} // namespace infrastructure