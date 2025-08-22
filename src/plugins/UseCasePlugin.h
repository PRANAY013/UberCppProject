#pragma once

#include <drogon/plugins/Plugin.h>
#include "../application/UseCases/RequestRideUseCase.h"
#include "../infrastructure/routing/LocalRouterAdapter.h"
#include "../domain/trip/Matching.h"
#include "../infrastructure/persistence/InMemoryRiderRepository.h"
#include "../infrastructure/persistence/InMemoryDriverRepository.h"
#include "../infrastructure/persistence/InMemoryTripRepository.h"

namespace plugins {

class UseCasePlugin : public drogon::Plugin<UseCasePlugin> {
public:
    UseCasePlugin() = default;
    /// This method is called when the plugin is loaded.
    /// It is assumed that the plugin is a singleton.
    void initAndStart(const Json::Value &config) override;

    /// This method is called when the plugin is unloaded.
    void shutdown() override;

    application::UseCases::RequestRideUseCase& getRequestRideUseCase() { return *requestRideUseCase_; }

private:
    infrastructure::routing::LocalRouterAdapter localRouter_;
    infrastructure::persistence::InMemoryRiderRepository riderRepository_;
    infrastructure::persistence::InMemoryDriverRepository driverRepository_;
    infrastructure::persistence::InMemoryTripRepository tripRepository_;
    domain::Matching matchingService_;
    std::unique_ptr<application::UseCases::RequestRideUseCase> requestRideUseCase_;
};

} // namespace plugins
