#include "FareCalculator.h"

namespace domain {
namespace pricing {

FareCalculator::FareCalculator() {}

double FareCalculator::calculateFare(
    double distance_km, double duration_min,
    const SurgeModel& surge, int zone_id) const noexcept {
    constexpr double BASE_FARE    = 20.0;
    constexpr double PER_KM_RATE  = 12.0;
    constexpr double PER_MIN_RATE = 2.0;
    double base = BASE_FARE + (distance_km * PER_KM_RATE) + (duration_min * PER_MIN_RATE);
    return base * surge.getMultiplier(zone_id);
}

} // namespace pricing
} // namespace domain
