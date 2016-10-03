cmake_minimum_required(VERSION 3.5)
project(Assn2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp node.hpp TreeStarter.cpp TreeStarter.hpp)
add_executable(Assn2 ${SOURCE_FILES})