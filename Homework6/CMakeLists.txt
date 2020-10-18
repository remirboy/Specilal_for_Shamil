cmake_minimum_required(VERSION 3.17)
project(Homework6)

set(CMAKE_CXX_STANDARD 14)

add_executable(Homework6 main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

include_directories(/usr/include/mpi/)

set(CMAKE_C_COMPILER "/usr/bin/mpicc")
set(CMAKE_CXX_COMPILER "/usr/local/bin/g++")