#ifndef FARECALCULATOR_H
#define FARECALCULATOR_H

#include "SurgeModel.h"

namespace domain {
namespace pricing {
class FareCalculator {
public:
    FareCalculator(); // Constructor

    // A simple fare calculation for now.
    // We will add more complex parameters like distance, duration, and surge pricing later.
    double calculateFare(const SurgeModel& surgeModel) const;
};
} // namespace pricing
} // namespace domain

#endif // FARECALCULATOR_H
