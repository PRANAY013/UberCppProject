#include "SurgeModel.h"

namespace domain {
namespace pricing {

SurgeModel::SurgeModel() {}

// A simple surge model for now.
// In the future, this would take inputs like time, area demand, and supply.
double SurgeModel::getMultiplier() const {
    // Let's assume a fixed surge multiplier for now.
    return 1.2;
}

} // namespace pricing
} // namespace domain
