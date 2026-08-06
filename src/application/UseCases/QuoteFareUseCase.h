#ifndef QUOTEFAREUSECASE_H
#define QUOTEFAREUSECASE_H

#include "../../domain/pricing/FareCalculator.h"
#include "../../domain/pricing/SurgeModel.h"
#include "../../domain/routing/Router.h"
#include "../../domain/trip/Trip.h"
#include "../../domain/geo/GeoPoint.h"

namespace application {
namespace UseCases {
class QuoteFareUseCase {
public:
    struct QuoteResult {
        double fare;
        double surge_multiplier;
        double distance_km;
    };

    QuoteFareUseCase(const domain::pricing::FareCalculator& fareCalculator, const domain::pricing::SurgeModel& surgeModel, const domain::routing::Router& router);

    QuoteResult execute(const domain::geo::GeoPoint& start, const domain::geo::GeoPoint& end) const;

private:
    const domain::pricing::FareCalculator& fareCalculator;
    const domain::pricing::SurgeModel& surgeModel;
    const domain::routing::Router& router;
};
} // namespace UseCases
} // namespace application

#endif // QUOTEFAREUSECASE_H
