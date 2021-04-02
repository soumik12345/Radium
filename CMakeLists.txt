cmake_minimum_required(VERSION 3.12)
project(radium)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-fopenmp")

file(GLOB source_files "${CMAKE_SOURCE_DIR}/src/lib/*.cpp")
include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/lib/headers)

add_executable(radium ${source_files} src/main.cpp)
