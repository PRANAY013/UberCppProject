#include <benchmark/benchmark.h>
#include "../src/infrastructure/MemoryPool.h"
#include "../src/domain/driver/Driver.h"
#include <memory>
#include <vector>

using namespace infrastructure;
using namespace domain;

static void BM_ObjectPoolAllocDealloc(benchmark::State& state) {
    ObjectPool<Driver, 10000> pool;
    for (auto _ : state) {
        Driver* d = pool.allocate();
        new (d) Driver(1, Driver::Status::Idle, 5.0, "Car", geo::GeoPoint(0, 0));
        benchmark::DoNotOptimize(d);
        d->~Driver();
        pool.deallocate(d);
    }
}
BENCHMARK(BM_ObjectPoolAllocDealloc);

static void BM_NewDeleteAllocDealloc(benchmark::State& state) {
    for (auto _ : state) {
        Driver* d = new Driver(1, Driver::Status::Idle, 5.0, "Car", geo::GeoPoint(0, 0));
        benchmark::DoNotOptimize(d);
        delete d;
    }
}
BENCHMARK(BM_NewDeleteAllocDealloc);

static void BM_MakeUniqueAllocDealloc(benchmark::State& state) {
    for (auto _ : state) {
        auto d = std::make_unique<Driver>(1, Driver::Status::Idle, 5.0, "Car", geo::GeoPoint(0, 0));
        benchmark::DoNotOptimize(d);
    }
}
BENCHMARK(BM_MakeUniqueAllocDealloc);
