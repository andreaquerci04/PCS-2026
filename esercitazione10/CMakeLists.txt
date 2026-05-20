cmake_minimum_required(VERSION 3.20)
project(esercitazione8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)

set(SOURCES test.cpp)
add_executable(test test.cpp)

target_link_libraries(test Eigen3::Eigen)