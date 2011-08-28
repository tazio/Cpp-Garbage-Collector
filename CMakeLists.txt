project(cpp-garbage-collector)
cmake_minimum_required(VERSION 2.6)

add_definitions(${CMAKE_CXX_FLAGS} "-std=c++0x")
add_executable(cpp-garbage-collector main.cpp)

add_subdirectory(library)
