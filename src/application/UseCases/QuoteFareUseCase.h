#ifndef QUOTEFAREUSECASE_H
#define QUOTEFAREUSECASE_H

#include "../../domain/pricing/FareCalculator.h"
#include "../../domain/pricing/SurgeModel.h"
#include "../../domain/trip/Trip.h" // Or just relevant details like distance/duration

class QuoteFareUseCase {
public:
    QuoteFareUseCase(const FareCalculator& fareCalculator, const SurgeModel& surgeModel);

    // For now, a simple quote based on existing models.
    // Later, this could take trip details like distance, duration, etc.
    double execute() const;

private:
    const FareCalculator& fareCalculator;
    const SurgeModel& surgeModel;
};

#endif // QUOTEFAREUSECASE_H
