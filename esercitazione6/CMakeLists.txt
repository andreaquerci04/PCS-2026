cmake_minimum_required(VERSION 3.20)

project(esercitazione8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES  testing_grafo.cpp)

add_executable(test_grafo testing_grafo.cpp)
