cmake_minimum_required(VERSION 3.16.0)
set(CMAKE_GENERATOR "Unix Makefiles")
project(dstruct VERSION 0.0.1 DESCRIPTION "A C data structure library")

include(GNUInstallDirs)

# Check for Math library (Linux)
find_library(m OPTIONAL)

set(CMAKE_SOURCE_DIR dstruct/src)

set(dstruct_SRC ${CMAKE_SOURCE_DIR}/bst.c ${CMAKE_SOURCE_DIR}/llist.c ${CMAKE_SOURCE_DIR}/dllist.c)

add_library(dstruct SHARED ${dstruct_SRC})
target_include_directories(dstruct PRIVATE include/dstruct)
