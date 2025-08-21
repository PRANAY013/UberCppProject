#include "GoogleRouterAdapter.h"

namespace infrastructure {
namespace routing {

GoogleRouterAdapter::GoogleRouterAdapter(const http::GoogleMapsClient& client) : client(client) {}

std::optional<domain::routing::RoutePlan> GoogleRouterAdapter::findRoute(const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end) const {
    // This implementation uses the GoogleMapsClient to get directions.
    // Since GoogleMapsClient's getDirections is currently a mock, this will also be a mock.
    // In a real scenario, the client would make an actual HTTP request.
    return client.getDirections(start, end);
}

} // namespace routing
} // namespace infrastructure
