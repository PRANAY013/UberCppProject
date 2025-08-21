#include "FareCalculator.h"

namespace domain {
namespace pricing {

FareCalculator::FareCalculator() {}

// A simple fare calculation for now.
// We will add more complex parameters like distance, duration, and surge pricing later.
double FareCalculator::calculateFare(const SurgeModel& surgeModel) const {
    // Let's assume a flat base fare for now.
    double baseFare = 15.50;
    return baseFare * surgeModel.getMultiplier();
}

} // namespace pricing
} // namespace domain
