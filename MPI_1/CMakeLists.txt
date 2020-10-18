cmake_minimum_required(VERSION 3.6)
project(MPI_1)

include_directories(/usr/include/mpi/)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -open-mpi")

find_package(MPI REQUIRED)
#include_directories(${MPI_INCLUDE_PATH})

set(CMAKE_CXX_COMPILER "/usr/local/bin/mpicc")
set(CMAKE_CXX_COMPILER "/usr/local/bin/mpicxx")

set(SOURCE_FILES main.cpp)
add_executable(MPI_1 ${SOURCE_FILES})