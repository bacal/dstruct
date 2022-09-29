cmake_minimum_required(VERSION 3.16.0)
project(dstruct VERSION 0.0.1 DESCRIPTION "A C data structure library")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(dstruct PRIVATE include/)

add_library(dstruct SHARED src/bst.c
                           src/llist.c
                           src/dllist.c
                           src/stack.c
                           src/dyarray.c)



