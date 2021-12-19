cmake_minimum_required(VERSION 3.16.0)
project(dstruct_tests)

set(CMAKE_GENERATOR "Unix Makefiles")

include(GoogleTest)

add_subdirectory(dstruct)

add_subdirectory(tests)
