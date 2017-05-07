cmake_minimum_required(VERSION 3.6)
project(testC11)

set(CMAKE_CXX_FLAGS  "-std=c++0x -pthread")

set(SOURCE_FILES main.cpp)
add_executable(testC11 ${SOURCE_FILES})