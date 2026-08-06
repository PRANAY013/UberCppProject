# Uber High-Throughput Spatial Matching Engine

A highly optimized, modular C++17 backend engineered to simulate the core spatial matching and dynamic pricing engines of a ride-sharing platform like Uber.

Built from the ground up using **Domain-Driven Design (DDD)**, this project entirely bypasses standard O(n) geospatial algorithms and kernel memory allocators to achieve extreme, lock-free performance under high concurrent loads.

## 🚀 Key Architectural Highlights

*   **O(1) Spatial Grid Matching:** Replaced standard linear Haversine scans with a cache-friendly, constant-time Spatial Grid.
*   **Zero-Allocation Surge Engine:** The core pricing engine is designed using pre-allocated `std::array` memory and atomic load/store primitives, rendering the critical pricing path entirely lock-free with zero dynamic heap allocations.
*   **Custom Freelist Object Pool:** Location ingestion pipelines utilize a custom Object Pool over contiguous `aligned_storage_t`, completely bypassing kernel `malloc`/`free` context switching.
*   **Concurrent Threading:** Thread-safe reads are guaranteed via `std::shared_mutex`, allowing Drogon's web workers to concurrently read driver locations while the background task queue updates them.

## 📊 Google Benchmark Metrics

Performance isn't guessed; it is mathematically verified using `Google Benchmark` to prevent compiler elision.

| Architecture | Naive Approach | Optimized Solution | Speedup |
| :--- | :--- | :--- | :--- |
| **Driver Discovery (10k drivers)** | 451 µs (Linear Scan) | **26 µs** (Spatial Grid) | **17.4x Faster** |
| **Location Telemetry Lifecycle** | 47 ns (`std::make_unique`) | **27 ns** (Freelist Object Pool) | **1.7x Faster** |

## 🛠️ Technology Stack
*   **Language:** C++17
*   **Web Framework:** Drogon (High-performance async C++ framework)
*   **Concurrency:** `std::shared_mutex`, `std::atomic`, `std::condition_variable`
*   **Testing:** Google Benchmark
*   **Build System:** CMake

## 📦 Building & Running

```bash
# Build the core application
make build

# Run the REST server on 127.0.0.1:8848
make run

# Run the Google Benchmark suite
make build && ./build/uber_benchmarks
```

## 📡 Core API Endpoints

*   `POST /api/v1/ride/quote` - Calculates live geospatial distance and dynamic fare.
*   `POST /api/v1/ride/request` - Triggers O(1) matching engine to find the nearest driver.
*   `POST /api/v1/driver/location` - Asynchronous HTTP 202 endpoint pushing GPS coordinates into the ObjectPool memory queue.
*   `GET /api/v1/ride/{id}/status` - Queries the in-memory repository for trip status.