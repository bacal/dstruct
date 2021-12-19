cmake_minimum_required(VERSION 3.16.0)
project(demo)

set(CMAKE_GENERATOR "Unix Makefiles")

add_subdirectory(dstruct)
enable_testing()
add_subdirectory(tests)
add_test(AllTestsInTests tests)
