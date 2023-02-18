cmake_minimum_required(VERSION 3.21.0)
project(dstruct VERSION 0.0.1 DESCRIPTION "A C data structure library")

include(GNUInstallDirs)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(dstruct PRIVATE include/)

add_library(dstruct SHARED src/bst.c
                           src/llist.c
                           src/dllist.c
                           src/stack.c
                           src/dyarray.c)

set_target_properties(dstruct PROPERTIES PUBLIC_HEADER include/dstruct.h)
set_target_properties(dstruct PROPERTIES PRIVATE_HEADER "include/bst.h;include/llist.h;include/dllist.h;include/stack.h;include/dyarray.h;" )

install(TARGETS dstruct

        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include/dstruct
        PRIVATE_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include/dstruct
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)


