#include <benchmark/benchmark.h>
#include "../src/domain/geo/SpatialGrid.h"
#include "../src/domain/geo/GeoPoint.h"
#include "../src/domain/driver/Driver.h"
#include <vector>
#include <cmath>
#include <random>
#include <string>

using namespace domain::geo;
using namespace domain;

static void BM_SpatialGridQuery(benchmark::State& state) {
    SpatialGrid grid;
    std::mt19937 gen(42);
    std::uniform_real_distribution<double> lat_dist(40.0, 41.0);
    std::uniform_real_distribution<double> lon_dist(-74.0, -73.0);

    for (int i = 0; i < 10000; ++i) {
        Driver d(i, Driver::Status::Idle, 5.0, "Car" + std::to_string(i), GeoPoint(lat_dist(gen), lon_dist(gen)));
        grid.insert(d);
    }

    GeoPoint center(40.5, -73.5);
    double radius_km = 5.0; // Needs to be <= CELL_SIZE_KM (5.55)

    for (auto _ : state) {
        auto result = grid.queryNeighborhood(center, radius_km);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_SpatialGridQuery);

static void BM_LinearScanQuery(benchmark::State& state) {
    std::vector<Driver> drivers;
    drivers.reserve(10000);
    std::mt19937 gen(42);
    std::uniform_real_distribution<double> lat_dist(40.0, 41.0);
    std::uniform_real_distribution<double> lon_dist(-74.0, -73.0);

    for (int i = 0; i < 10000; ++i) {
        drivers.emplace_back(i, Driver::Status::Idle, 5.0, "Car" + std::to_string(i), GeoPoint(lat_dist(gen), lon_dist(gen)));
    }

    GeoPoint center(40.5, -73.5);
    double radius_km = 5.0;

    for (auto _ : state) {
        std::vector<Driver> result;
        for (const auto& d : drivers) {
            if (haversineDistance(d.getLocation(), center) <= radius_km * 1000.0) {
                result.push_back(d);
            }
        }
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_LinearScanQuery);
