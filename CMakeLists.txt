cmake_minimum_required (VERSION 2.6)
project (EXACT_COVER)

set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g ")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")

enable_testing()

include_directories(src)
add_subdirectory(src)
#test
add_subdirectory(test)
