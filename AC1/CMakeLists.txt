cmake_minimum_required(VERSION 3.29)
project(AC1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AC1
        main.cpp
        autocompleter.cpp)
