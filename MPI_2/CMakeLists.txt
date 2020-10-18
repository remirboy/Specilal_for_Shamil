cmake_minimum_required(VERSION 3.6)
project(MPI_2)

include_directories(/usr/include/mpi/)

find_package(MPI REQUIRED)

set(CMAKE_CXX_COMPILER "/usr/local/bin/mpicc")
set(CMAKE_CXX_COMPILER "/usr/local/bin/mpicxx")

set(SOURCE_FILES main.cpp)
add_executable(MPI_2 ${SOURCE_FILES})