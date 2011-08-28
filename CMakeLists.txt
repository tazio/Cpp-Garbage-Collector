project(cpp-garbage-collector)

add_definitions(${CMAKE_CXX_FLAGS} "-std=c++0x")
add_executable(cpp-garbage-collector main.cpp)


add_subdirectory(library)