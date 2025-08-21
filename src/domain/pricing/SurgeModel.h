#ifndef SURGEMODEL_H
#define SURGEMODEL_H

namespace domain {
namespace pricing {
class SurgeModel {
public:
    SurgeModel();

    // A simple surge model for now.
    // In the future, this would take inputs like time, area demand, and supply.
    double getMultiplier() const;
};
} // namespace pricing
} // namespace domain

#endif // SURGEMODEL_H
