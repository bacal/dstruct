cmake_minimum_required(VERSION 3.16.0)
project(dstruct VERSION 0.0.1 DESCRIPTION "A C data structure library")

include(GNUInstallDirs)

add_library(dstruct SHARED)
target_include_directories(dstruct PRIVATE include/dstruct)

target_sources(dstruct PRIVATE src/bst.c
                               src/llist.c
                               src/dllist.c
                               src/stack.c
                               src/dyarray.c)



