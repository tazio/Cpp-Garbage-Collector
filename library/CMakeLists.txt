include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(C++GC_SRCS
    dummy_allocator.hpp
    smart_pointers.hpp
    utilities.hpp
)

add_library(C++GC SHARED ${C++GC_SRCS})
add_library(C++GC_static STATIC ${C++GC_SRCS})

SET_TARGET_PROPERTIES(C++GC PROPERTIES LINKER_LANGUAGE CXX)
SET_TARGET_PROPERTIES(C++GC_static PROPERTIES LINKER_LANGUAGE CXX)

SET_TARGET_PROPERTIES(C++GC_static PROPERTIES OUTPUT_NAME "C++GC")
SET_TARGET_PROPERTIES(C++GC_static PROPERTIES PREFIX "lib")
# Help CMake 2.6.x and lower (not necessary for 2.8 and above, but doesn't hurt):
SET_TARGET_PROPERTIES(C++GC PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(C++GC_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

#install(TARGETS C++GC DESTINATION lib)
#FILE(GLOB headers "*.h")
#install(FILES ${headers} DESTINATION include/C++GC)
