cmake_minimum_required(VERSION 3.29)
project(blnd)

set(CMAKE_CXX_STANDARD 20)

add_executable(blnd main.cpp
        wordblender.cpp)
