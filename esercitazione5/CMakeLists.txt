cmake_minimum_required(VERSION 3.20)
project(esercitazione4) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

add_executable(test_bubblesort test_bubblesort.cpp timecounter.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

add_executable(test_inserctionsort test_inserctionsort.cpp timecounter.cpp)
add_test(NAME inserctionsort COMMAND test_inserctionsort)

add_executable(test_selectionsort test_selectionsort.cpp timecounter.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

add_executable(test_sortingnativo test_sortingnativo.cpp timecounter.cpp)

add_executable(test_quicksort test_quicksort.cpp timecounter.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

add_executable(test_mergesort test_mergesort.cpp timecounter.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

add_executable(test_mixsort test_mixsort.cpp timecounter.cpp)
add_test(NAME mixsort COMMAND test_mixsort)

enable_testing()


