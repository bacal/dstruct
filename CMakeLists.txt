cmake_minimum_required(VERSION 3.16.0)
project(demo)

set(CMAKE_GENERATOR "Unix Makefiles")

add_subdirectory(dstruct)

enable_testing()
add_executable(tester)
target_include_directories(tester PRIVATE dstruct/include)
target_sources(tester PRIVATE tester.c)
target_link_libraries(tester dstruct)

add_test(Test tester)
