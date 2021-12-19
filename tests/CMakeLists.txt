cmake_minimum_required(VERSION 3.20)
project(tests)

include(GoogleTest)
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 11)
enable_testing()
include_directories(../dstruct/include)
add_executable(llist_tests llist_tests.cpp)

target_link_libraries(llist_tests GTest::gtest GTest::gtest_main dstruct)
gtest_discover_tests(llist_tests)

