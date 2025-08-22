#include "UseCasePlugin.h"

using namespace plugins;

void UseCasePlugin::initAndStart(const Json::Value &config) {
    /// Initialize and start the plugin
    requestRideUseCase_ = std::make_unique<application::UseCases::RequestRideUseCase>(
        localRouter_,
        matchingService_,
        riderRepository_,
        tripRepository_
    );

    // Add a dummy rider for testing
    domain::Rider dummyRider(1, 4.9, "Standard Preferences");
    riderRepository_.save(dummyRider);
}

void UseCasePlugin::shutdown() {
    /// Shutdown the plugin
}
