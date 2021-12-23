cmake_minimum_required(VERSION 3.20)
project(tests)

include(GoogleTest)
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 11)
enable_testing()
include_directories(../dstruct/include)
add_executable(dstruct_tests llist_tests.cpp
			     bst_tests.cpp)

target_link_libraries(dstruct_tests GTest::gtest GTest::gtest_main dstruct)
gtest_discover_tests(dstruct_tests)

