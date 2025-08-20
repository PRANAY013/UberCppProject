cmake_minimum_required(VERSION 3.10)
project(UberCppProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add a library for our domain objects
# --- Domain Library ---
# Contains the core business logic and entities.
add_library(domain
    src/domain/rider/Rider.h
    src/domain/rider/Rider.cc
    src/domain/rider/RiderHistory.h
    src/domain/rider/RiderHistory.cc
    src/domain/driver/Driver.h
    src/domain/driver/Driver.cc
    src/domain/driver/DriverHistory.h
    src/domain/driver/DriverHistory.cc
    src/domain/trip/Trip.h
    src/domain/trip/Trip.cc
    src/domain/trip/Matching.h
    src/domain/trip/Matching.cc
    src/domain/routing/Router.h
    src/domain/routing/RoutePlan.h
    src/domain/routing/RoutePlan.cc
    src/domain/geo/GeoPoint.h
    src/domain/geo/GeoPoint.cc
    src/domain/geo/GeoFence.h
    src/domain/geo/GeoFence.cc
    src/domain/geo/Place.h
    src/domain/geo/Place.cc
    src/domain/pricing/FareCalculator.h
    src/domain/pricing/FareCalculator.cc
    src/domain/pricing/SurgeModel.h
    src/domain/pricing/SurgeModel.cc
)

# --- Application Library ---
# Contains the application-specific use cases.
add_library(application
    src/application/UseCases/RequestRideUseCase.h
    src/application/UseCases/RequestRideUseCase.cc
    src/application/UseCases/QuoteFareUseCase.h
    src/application/UseCases/QuoteFareUseCase.cc
    src/application/UseCases/AssignDriverUseCase.h
    src/application/UseCases/AssignDriverUseCase.cc
    src/application/UseCases/UpdateLocationUseCase.h
    src/application/UseCases/UpdateLocationUseCase.cc
    src/application/UseCases/ShareRideStatusUseCase.h
    src/application/UseCases/ShareRideStatusUseCase.cc
)

# The application layer depends on the domain layer.
target_link_libraries(application domain)

# --- Infrastructure Library ---
# Contains concrete implementations of domain interfaces.
add_library(infrastructure
    src/infrastructure/routing/MockRouterAdapter.h
    src/infrastructure/routing/MockRouterAdapter.cc
    src/infrastructure/persistence/IRepository.h
    src/infrastructure/persistence/InMemoryRiderRepository.h
    src/infrastructure/persistence/InMemoryRiderRepository.cc
    src/infrastructure/persistence/InMemoryDriverRepository.h
    src/infrastructure/persistence/InMemoryDriverRepository.cc
    src/infrastructure/persistence/InMemoryTripRepository.h
    src/infrastructure/persistence/InMemoryTripRepository.cc
)

# The infrastructure layer depends on the domain layer.
target_link_libraries(infrastructure domain)


# --- Main Executable ---
# The entry point of the application.
add_executable(uber_app src/main.cpp)
target_link_libraries(uber_app application infrastructure) # Now links to application instead of domain
