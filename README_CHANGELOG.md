# Project Changelog

This file logs all significant changes, additions, and modifications made to the project.

## [2025-08-21] - Core System Implementation

This release marks the initial implementation of the core functionalities of the Uber-like ride-sharing service. The project is structured following a clean, domain-driven architecture.

### Key Features:

-   **Domain Layer:**
    -   **Core Models:** `Rider`, `Driver`, and `Trip` models with their respective states and properties.
    -   **Geography:** `GeoPoint` and `GeoFence` for handling geographical data and area restrictions. The `GeoFence` contains a robust ray-casting algorithm for point-in-polygon checks.
    -   **Pricing:** `FareCalculator` and `SurgeModel` for calculating ride fares and applying surge pricing.
    -   **Routing:** A `Router` interface with a `RoutePlan` model for route calculations.
    -   **Trip Matching:** A `Matching` service to connect riders with available drivers.

-   **Application Layer:**
    -   **Use Cases:** A suite of use cases to handle primary user actions, including `RequestRideUseCase`, `QuoteFareUseCase`, `AssignDriverUseCase`, `UpdateLocationUseCase`, and `ShareRideStatusUseCase`.

-   **Infrastructure Layer:**
    -   **Routing Adapters:** A `MockRouterAdapter` for testing and a `LocalRouterAdapter` for basic, local route calculations.
    -   **Persistence:** In-memory repositories (`InMemoryRiderRepository`, `InMemoryDriverRepository`, `InMemoryTripRepository`) for data storage during runtime.
    -   **External Services (Mocks):** A mock `GoogleMapsClient` for simulating interactions with the Google Maps API, an `EventBus` for in-process messaging, and a `PaymentsGateway` for handling payment processing.

-   **Interfaces Layer:**
    -   **REST Controller (Simulated):** A `RideController` to simulate handling of incoming ride requests, with a `RideRequestDTO` for data transfer.

-   **Build System:**
    -   The project is configured with CMake for a consistent and reliable build process.
