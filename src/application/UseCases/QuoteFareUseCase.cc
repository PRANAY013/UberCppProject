#include "QuoteFareUseCase.h"

namespace application {
namespace UseCases {

QuoteFareUseCase::QuoteFareUseCase(const domain::pricing::FareCalculator& fareCalculator, const domain::pricing::SurgeModel& surgeModel)
    : fareCalculator(fareCalculator), surgeModel(surgeModel) {}

double QuoteFareUseCase::execute() const {
    // For now, we'll just use the existing fare calculation without specific trip details.
    // In the future, this method would take parameters like distance, duration, etc.
    return fareCalculator.calculateFare(surgeModel);
}

} // namespace UseCases
} // namespace application
