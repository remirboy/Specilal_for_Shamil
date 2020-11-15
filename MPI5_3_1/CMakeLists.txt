cmake_minimum_required(VERSION 3.17)
project(MPI5_3_1)
find_package(MPI REQUIRED)

set(CMAKE_CXX_COMPILER "/usr/local/bin/mpicc")
set(CMAKE_CXX_COMPILER "/usr/local/bin/mpicxx")

set(CMAKE_CXX_STANDARD 14)

add_executable(MPI5_3_1 main.cpp)