cmake_minimum_required(VERSION 3.5)
project(Assn5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp SkewHeapMin.hpp SkewHeapMax.hpp SkewHeapMin.cpp SkewHeapMax.cpp Median.hpp Median.cpp Node.hpp)
add_executable(Assn5 ${SOURCE_FILES})
