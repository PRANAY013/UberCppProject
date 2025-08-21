#ifndef ASSIGNDRIVERUSECASE_H
#define ASSIGNDRIVERUSECASE_H

#include "../../domain/trip/Trip.h"
#include "../../domain/driver/Driver.h"

namespace application {
namespace UseCases {
class AssignDriverUseCase {
public:
    AssignDriverUseCase();

    // Assigns a driver to a trip.
    // In a real scenario, this would update the trip in a repository
    // and potentially update the driver's status.
    void execute(domain::Trip& trip, const domain::Driver& driver);
};
} // namespace UseCases
} // namespace application

#endif // ASSIGNDRIVERUSECASE_H
