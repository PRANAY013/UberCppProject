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

void interfaces::rest::RideController::quoteFare(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
    auto jsonBody = req->getJsonObject();
    if (!jsonBody) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k400BadRequest);
        callback(resp);
        return;
    }
    double startLat = (*jsonBody)["startLat"].asDouble();
    double startLon = (*jsonBody)["startLon"].asDouble();
    double endLat = (*jsonBody)["endLat"].asDouble();
    double endLon = (*jsonBody)["endLon"].asDouble();

    auto* plugin = drogon::app().getPlugin<plugins::UseCasePlugin>();
    auto& useCase = plugin->getQuoteFareUseCase();
    auto result = useCase.execute(domain::geo::GeoPoint(startLat, startLon), domain::geo::GeoPoint(endLat, endLon));

    Json::Value ret;
    ret["fare"] = result.fare;
    ret["surge_multiplier"] = result.surge_multiplier;
    ret["distance_km"] = result.distance_km;
    callback(drogon::HttpResponse::newHttpJsonResponse(ret));
}

void interfaces::rest::RideController::updateLocation(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
    auto jsonBody = req->getJsonObject();
    if (!jsonBody) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k400BadRequest);
        callback(resp);
        return;
    }
    int driverId = (*jsonBody)["driverId"].asInt();
    double lat = (*jsonBody)["lat"].asDouble();
    double lon = (*jsonBody)["lon"].asDouble();

    auto* plugin = drogon::app().getPlugin<plugins::UseCasePlugin>();
    plugin->getLocationQueue().push(driverId, domain::geo::GeoPoint(lat, lon));

    auto resp = drogon::HttpResponse::newHttpResponse();
    resp->setStatusCode(drogon::k202Accepted);
    callback(resp);
}

void interfaces::rest::RideController::getTripStatus(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback, int trip_id) {
    auto* plugin = drogon::app().getPlugin<plugins::UseCasePlugin>();
    auto trip = plugin->getTripRepository().findById(trip_id);
    
    if (trip) {
        Json::Value ret;
        ret["tripId"] = trip->getId();
        ret["status"] = "Found"; // Just a simple status string for now
        callback(drogon::HttpResponse::newHttpJsonResponse(ret));
    } else {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k404NotFound);
        callback(resp);
    }
}
