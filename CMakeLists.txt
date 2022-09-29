cmake_minimum_required(VERSION 3.16.0)
project(dstruct_tests)

set(CMAKE_GENERATOR "Unix Makefiles")

enable_testing()

add_subdirectory(dstruct)
add_subdirectory(tests)
