#include "UseCasePlugin.h"

using namespace plugins;

void UseCasePlugin::initAndStart(const Json::Value &config) {
    /// Initialize and start the plugin
    requestRideUseCase_ = std::make_unique<application::UseCases::RequestRideUseCase>(
        localRouter_,
        matchingService_,
        riderRepository_,
        tripRepository_,
        driverRepository_
    );

    quoteFareUseCase_ = std::make_unique<application::UseCases::QuoteFareUseCase>(
        fareCalculator_,
        surgeModel_,
        localRouter_
    );

    // Add a dummy rider for testing
    domain::Rider dummyRider(1, 4.9, "Standard Preferences");
    riderRepository_.save(dummyRider);

    location_worker_ = std::thread([this]() {
        using namespace std::chrono_literals;
        while (auto upd = location_queue_.pop(50ms)) {
            driverRepository_.updateDriverLocation(upd->driver_id, upd->new_location);
        }
    });
}

void UseCasePlugin::shutdown() {
    location_queue_.stop();
    if (location_worker_.joinable()) {
        location_worker_.join();
    }
}
