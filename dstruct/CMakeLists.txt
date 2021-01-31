cmake_minimum_required(VERSION 3.16.0)
project(dstruct VERSION 0.0.1 DESCRIPTION "A C data structure library")

include(GNUInstallDirs)

add_library(dstruct SHARED)
target_include_directories(dstruct PRIVATE include/)

target_sources(dstruct PRIVATE src/bst
                               src/llist
                               src/dllist
                               src/stack
                               src/dyarray)



