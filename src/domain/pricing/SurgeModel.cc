#include "SurgeModel.h"

namespace domain {
namespace pricing {

SurgeModel::SurgeModel() {}

double SurgeModel::getMultiplier(int zone_id) const noexcept {
    double r = zone_metrics_[zone_id].active_riders.load(std::memory_order_relaxed);
    double d = zone_metrics_[zone_id].available_drivers.load(std::memory_order_relaxed);
    return std::max(1.0, 1.0 + 0.4 * (r / std::max(1.0, d) - 1.0));
}

void SurgeModel::updateZone(int zone_id, int riders, int drivers) noexcept {
    zone_metrics_[zone_id].active_riders.store(riders, std::memory_order_relaxed);
    zone_metrics_[zone_id].available_drivers.store(drivers, std::memory_order_relaxed);
}

} // namespace pricing
} // namespace domain
