#ifndef QUOTEFAREUSECASE_H
#define QUOTEFAREUSECASE_H

#include "../../domain/pricing/FareCalculator.h"
#include "../../domain/pricing/SurgeModel.h"
#include "../../domain/trip/Trip.h"

namespace application {
namespace UseCases {
class QuoteFareUseCase {
public:
    QuoteFareUseCase(const domain::pricing::FareCalculator& fareCalculator, const domain::pricing::SurgeModel& surgeModel);

    // For now, a simple quote based on existing models.
    // Later, this could take trip details like distance, duration, etc.
    double execute() const;

private:
    const domain::pricing::FareCalculator& fareCalculator;
    const domain::pricing::SurgeModel& surgeModel;
};
} // namespace UseCases
} // namespace application

#endif // QUOTEFAREUSECASE_H
