#pragma once

#include <drogon/plugins/Plugin.h>
#include "../application/UseCases/RequestRideUseCase.h"
#include "../application/UseCases/QuoteFareUseCase.h"
#include "../domain/pricing/FareCalculator.h"
#include "../domain/pricing/SurgeModel.h"
#include "../infrastructure/routing/LocalRouterAdapter.h"
#include "../domain/trip/Matching.h"
#include "../infrastructure/persistence/InMemoryRiderRepository.h"
#include "../infrastructure/persistence/InMemoryDriverRepository.h"
#include "../infrastructure/persistence/InMemoryTripRepository.h"
#include "../infrastructure/messaging/LocationUpdateQueue.h"
#include <thread>

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
    application::UseCases::QuoteFareUseCase& getQuoteFareUseCase() { return *quoteFareUseCase_; }
    infrastructure::persistence::InMemoryTripRepository& getTripRepository() { return tripRepository_; }
    infrastructure::messaging::LocationUpdateQueue& getLocationQueue() { return location_queue_; }

private:
    infrastructure::routing::LocalRouterAdapter localRouter_;
    infrastructure::persistence::InMemoryRiderRepository riderRepository_;
    infrastructure::persistence::InMemoryDriverRepository driverRepository_;
    infrastructure::persistence::InMemoryTripRepository tripRepository_;
    domain::Matching matchingService_;
    domain::pricing::FareCalculator fareCalculator_;
    domain::pricing::SurgeModel surgeModel_;

    std::unique_ptr<application::UseCases::RequestRideUseCase> requestRideUseCase_;
    std::unique_ptr<application::UseCases::QuoteFareUseCase> quoteFareUseCase_;
    infrastructure::messaging::LocationUpdateQueue location_queue_;
    std::thread location_worker_;
};

} // namespace plugins
