#pragma once

#include <drogon/HttpController.h>
#include "../../application/UseCases/RequestRideUseCase.h"

namespace interfaces::rest {

class RideController : public drogon::HttpController<RideController> {
  public:
    METHOD_LIST_BEGIN
    // list path definitions here;
    // METHOD_ADD(RideController::get, "/{2}/{1}", Get); // path is /interfaces/rest/RideController/{arg2}/{arg1}
    // METHOD_ADD(RideController::your_method_name, "/{1}/{2}/?", Get); // path is /interfaces/rest/RideController/{arg1}/{arg2}/ or /interfaces/rest/RideController/{arg1}/{arg2}
    ADD_METHOD_TO(RideController::requestRide, "/api/v1/ride/request", drogon::Post);
    ADD_METHOD_TO(RideController::quoteFare, "/api/v1/ride/quote", drogon::Post);
    ADD_METHOD_TO(RideController::updateLocation, "/api/v1/driver/location", drogon::Post);
    ADD_METHOD_TO(RideController::getTripStatus, "/api/v1/ride/{1}/status", drogon::Get);
    METHOD_LIST_END
    // your declaration of processing function
    // void get(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback, int p1, std::string p2);
    void requestRide(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback);
    void quoteFare(const drogon::HttpRequestPtr&, std::function<void(const drogon::HttpResponsePtr&)>&&);
    void updateLocation(const drogon::HttpRequestPtr&, std::function<void(const drogon::HttpResponsePtr&)>&&);
    void getTripStatus(const drogon::HttpRequestPtr&, std::function<void(const drogon::HttpResponsePtr&)>&&, int trip_id);
};

} // namespace interfaces::rest