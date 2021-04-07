cmake_minimum_required(VERSION 3.12)
message(STATUS "CMake version: ${CMAKE_VERSION}")

project(radium)

file(GLOB cpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cc")
file(GLOB gpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cu")

include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/lib)

enable_language("CUDA")
add_executable(radium ${cpu_source_files} ${gpu_source_files})
