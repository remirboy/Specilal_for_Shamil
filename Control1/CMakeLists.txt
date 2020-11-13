cmake_minimum_required(VERSION 3.17)
project(Control1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Control1 main.cpp)


set(CMAKE_CXX_COMPILER "/usr/local/bin/g++")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
