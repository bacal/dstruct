cmake_minimum_required(VERSION 3.20)
project(tests)

enable_testing()
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 11)
include_directories(../dstruct/include)
add_executable(llist_test tester.cpp)

target_link_libraries(llist_test GTest::gtest GTest::gtest_main dstruct)
