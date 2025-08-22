#include "RideController.h"
#include "RideRequestDTO.h"
#include "../../domain/geo/GeoPoint.h"
#include "../../plugins/UseCasePlugin.h"
#include <json/json.h>

void interfaces::rest::RideController::requestRide(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
    LOG_INFO << "Received ride request";
    auto jsonBody = req->getJsonObject();
    if (!jsonBody) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k400BadRequest);
        resp->setBody("Invalid JSON");
        callback(resp);
        return;
    }

    try {
        RideRequestDTO rideRequest;
        rideRequest.riderId = (*jsonBody)["riderId"].asInt();
        double startLat = (*jsonBody)["startLocation"]["latitude"].asDouble();
        double startLon = (*jsonBody)["startLocation"]["longitude"].asDouble();
        rideRequest.startLocation = domain::geo::GeoPoint(startLat, startLon);

        double endLat = (*jsonBody)["endLocation"]["latitude"].asDouble();
        double endLon = (*jsonBody)["endLocation"]["longitude"].asDouble();
        rideRequest.endLocation = domain::geo::GeoPoint(endLat, endLon);

        auto* plugin = drogon::app().getPlugin<plugins::UseCasePlugin>();
        auto& useCase = plugin->getRequestRideUseCase();
        auto trip = useCase.execute(rideRequest.riderId, rideRequest.startLocation, rideRequest.endLocation);

        Json::Value ret;
        if (trip) {
            ret["tripId"] = trip->getId();
            ret["message"] = "Ride requested successfully.";
        } else {
            ret["message"] = "Failed to request ride.";
        }

        auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
        callback(resp);

    } catch (const Json::Exception& e) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k400BadRequest);
        resp->setBody("JSON parsing error: " + std::string(e.what()));
        callback(resp);
    }
}
