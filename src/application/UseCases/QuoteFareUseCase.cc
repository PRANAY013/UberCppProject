#include "QuoteFareUseCase.h"

namespace application {
namespace UseCases {

QuoteFareUseCase::QuoteFareUseCase(const domain::pricing::FareCalculator& fareCalculator, const domain::pricing::SurgeModel& surgeModel, const domain::routing::Router& router)
    : fareCalculator(fareCalculator), surgeModel(surgeModel), router(router) {}

QuoteFareUseCase::QuoteResult QuoteFareUseCase::execute(const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end) const {
    auto routePlan = router.findRoute(start, end);
    if (routePlan) {
        double distance_km = routePlan->getDistance() / 1000.0;
        double duration_min = routePlan->getDuration() / 60.0;
        double surge = surgeModel.getMultiplier();
        double fare = fareCalculator.calculateFare(distance_km, duration_min, surgeModel);
        return {fare, surge, distance_km};
    }
    return {0.0, 1.0, 0.0};
}

} // namespace UseCases
} // namespace application
