cmake_minimum_required(VERSION 2.8)
project(ProgHF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES main.cpp Algorithms.h String.hpp TxtFile.hpp Vector.hpp)
add_executable(ProgHF ${SOURCE_FILES})
