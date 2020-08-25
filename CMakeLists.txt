cmake_minimum_required(VERSION 3.15)
project(Project2_MM)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project2_MM
        MatrixMultiply.h
        Project2.cpp
        main.cpp)
