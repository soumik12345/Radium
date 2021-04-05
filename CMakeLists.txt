cmake_minimum_required(VERSION 3.12)
project(radium)

set(CMAKE_CXX_STANDARD 14)

file(GLOB source_files "${CMAKE_SOURCE_DIR}/src/lib/*.cpp")
include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/lib/headers)

find_package(OpenMP)

add_executable(radium ${source_files} src/main.cpp)

if(OpenMP_CXX_FOUND)
    message("OpenMP Found")
    target_link_libraries(radium PUBLIC OpenMP::OpenMP_CXX)
endif()
