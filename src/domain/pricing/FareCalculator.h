#ifndef FARECALCULATOR_H
#define FARECALCULATOR_H

#include "SurgeModel.h"

namespace domain {
namespace pricing {
class FareCalculator {
public:
    FareCalculator(); // Constructor

    double calculateFare(double distance_km, double duration_min,
                         const SurgeModel& surge,
                         int zone_id = 0) const noexcept;
};
} // namespace pricing
} // namespace domain

#endif // FARECALCULATOR_H
