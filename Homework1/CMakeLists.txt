cmake_minimum_required(VERSION 3.17)
project(Homework1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Homework1 task1.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(CMAKE_CXX_COMPILER "/usr/local/bin/g++")