cmake_minimum_required(VERSION 3.17)
project(MPI_7)

include_directories(/usr/include/mpi/)

find_package(MPI REQUIRED)

set(CMAKE_CXX_COMPILER "/usr/local/bin/mpicc")
set(CMAKE_CXX_COMPILER "/usr/local/bin/mpicxx")

set(SOURCE_FILES main.cpp)
add_executable(MPI_7 ${SOURCE_FILES})