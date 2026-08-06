.PHONY: build debug run clean test-endpoints help

build:
	mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build . -j4

debug:
	mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && cmake --build . -j4

run: build
	./build/uber_app

clean:
	rm -rf build

test-endpoints:
	@echo "=== 1. Quote Fare ==="
	curl -s -X POST http://127.0.0.1:8848/api/v1/ride/quote \
		-H "Content-Type: application/json" \
		-d '{"startLat": 28.6139, "startLon": 77.2090, "endLat": 28.6353, "endLon": 77.2250}' | python3 -m json.tool
	@echo "\n=== 2. Request Ride ==="
	curl -s -X POST http://127.0.0.1:8848/api/v1/ride/request \
		-H "Content-Type: application/json" \
		-d '{"riderId": 1, "startLocation": {"latitude": 28.6139, "longitude": 77.2090}, "endLocation": {"latitude": 28.6353, "longitude": 77.2250}}' | python3 -m json.tool
	@echo "\n=== 3. Update Driver Location ==="
	curl -s -X POST http://127.0.0.1:8848/api/v1/driver/location \
		-H "Content-Type: application/json" \
		-d '{"driverId": 1, "lat": 28.6200, "lon": 77.2150}'
	@echo " (202 Accepted = success)"
	@echo "\n=== 4. Get Trip Status ==="
	curl -s -X GET http://127.0.0.1:8848/api/v1/ride/1/status | python3 -m json.tool || echo "404 = no trip with that ID yet"
	@echo ""

help:
	@echo "Available targets:"
	@echo "  build           - cmake configure + build (release)"
	@echo "  debug           - cmake configure + build (debug)"
	@echo "  run             - build then run the uber_app binary"
	@echo "  clean           - remove build directory"
	@echo "  test-endpoints  - curl all REST endpoints against localhost with sample JSON payloads"
	@echo "  help            - show available targets"
