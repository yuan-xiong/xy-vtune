cmake_minimum_required(VERSION 3.10)
project(xy-vtune)

### To get debug info
## way 1: ok
##add_definitions("-Wall -g")
#
## way 2: ok
#SET(CMAKE_CXX_FLAGS "-g -D_DEBUG -O0")
SET(CMAKE_CXX_FLAGS "-g -rdynamic -D_DEBUG -O0")
#
## way 3: ok with "cmake .. -DCMAKE_BUILD_TYPE=Debug"
##set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")
##SET(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG -O0")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(src)
