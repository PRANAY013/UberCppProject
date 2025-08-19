cmake_minimum_required(VERSION 3.10)
project(UberCppProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add a library for our domain objects
add_library(domain
    src/domain/rider/Rider.h
    src/domain/rider/Rider.cc
    src/domain/driver/Driver.h
    src/domain/driver/Driver.cc
    src/domain/trip/Trip.h
    src/domain/trip/Trip.cc
)

# Add the main executable
add_executable(uber_app src/main.cpp)
target_link_libraries(uber_app domain)
