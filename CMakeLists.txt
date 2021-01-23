cmake_minimum_required(VERSION 3.17)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 14)

file(GLOB source_files "${CMAKE_SOURCE_DIR}/src/lib/*.cpp")
include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/lib/headers)

add_executable(ray_tracer ${source_files} src/lib/Renderer.cpp src/main.cpp src/lib/headers/Vector3.hpp src/lib/Ray.cpp src/lib/headers/Ray.h src/lib/headers/Core.hpp)
