cmake_minimum_required(VERSION 3.16.0)
project(demo)

set(CMAKE_GENERATOR "Unix Makefiles")

add_subdirectory(dstruct)

enable_testing()
add_executable(demo)
target_include_directories(demo PRIVATE dstruct/include)
target_sources(demo PRIVATE demo.c)
target_link_libraries(demo dstruct)

add_test(Test demo)
