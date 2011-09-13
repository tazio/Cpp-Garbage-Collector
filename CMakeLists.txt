project(cpp-garbage-collector)
cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_definitions(${CMAKE_CXX_FLAGS} "-std=c++0x")

add_subdirectory(library)

add_executable(cpp-garbage-collector main.cpp)
target_link_libraries(cpp-garbage-collector C++GC)

add_subdirectory(test)