cmake_minimum_required(VERSION 3.10)
project(UberCppProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  drogon
  GIT_REPOSITORY https://github.com/drogonframework/drogon.git
  GIT_TAG master
)
FetchContent_MakeAvailable(drogon)

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
    src/infrastructure/routing/LocalRouterAdapter.h
    src/infrastructure/routing/LocalRouterAdapter.cc
    src/infrastructure/persistence/IRepository.h
    src/infrastructure/persistence/InMemoryRiderRepository.h
    src/infrastructure/persistence/InMemoryRiderRepository.cc
    src/infrastructure/persistence/InMemoryDriverRepository.h
    src/infrastructure/persistence/InMemoryDriverRepository.cc
    src/infrastructure/persistence/InMemoryTripRepository.h
    src/infrastructure/persistence/InMemoryTripRepository.cc
    src/infrastructure/http/GoogleMapsClient.h
    src/infrastructure/http/GoogleMapsClient.cc
    src/infrastructure/messaging/EventBus.h
    src/infrastructure/messaging/EventBus.cc
    src/infrastructure/payments/PaymentsGateway.h
    src/infrastructure/payments/PaymentsGateway.cc
)

# The infrastructure layer depends on the domain layer.
target_link_libraries(infrastructure domain)

# --- Interfaces Library ---
# Contains API controllers and DTOs.
add_library(interfaces
    src/interfaces/rest/RideRequestDTO.h
    src/interfaces/rest/RideController.h
    src/interfaces/rest/RideController.cc
)

# The interfaces layer depends on the application layer.
target_link_libraries(interfaces application drogon)

# --- Plugins Library ---
add_library(plugins SHARED
    src/plugins/UseCasePlugin.h
    src/plugins/UseCasePlugin.cc
)

target_link_libraries(plugins application infrastructure interfaces drogon)



# --- Main Executable ---
# The entry point of the application.
add_executable(uber_app src/main.cpp)
configure_file(config.json ${CMAKE_BINARY_DIR}/config.json COPYONLY)
target_link_libraries(uber_app application infrastructure interfaces plugins drogon)
