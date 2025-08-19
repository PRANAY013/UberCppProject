#ifndef FARECALCULATOR_H
#define FARECALCULATOR_H

#include "SurgeModel.h"

class FareCalculator {
public:
    FareCalculator(); // Constructor

    // A simple fare calculation for now.
    // We will add more complex parameters like distance, duration, and surge pricing later.
    double calculateFare(const SurgeModel& surgeModel) const;
};

#endif // FARECALCULATOR_H
