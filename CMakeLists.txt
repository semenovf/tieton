################################################################################
# Copyright (c) 2024 Vladislav Trifochkin
#
# This file is part of `tieton-lib`.
#
# Changelog:
#      2024.08.07 Initial version.
################################################################################
cmake_minimum_required (VERSION 3.11)
project(tieton-ALL CXX C)

# set(PFS__LOG_LEVEL 3 CACHE INTERNAL "Output trace log")
option(TIETON__BUILD_STRICT "Build with strict policies: C++ standard required, C++ extension is OFF etc" ON)
option(TIETON__BUILD_TESTS "Build tests" OFF)
option(TIETON__BUILD_DEMO "Build demo" OFF)
option(TIETON__ENABLE_COVERAGE "Build tests with coverage support" OFF)

if (NOT PORTABLE_TARGET__ENABLED)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/2ndparty/portable-target/cmake/v2)
    include(PortableTarget)
    portable_target(SET ENABLE_TRACE ON)
endif()

if (TIETON__BUILD_STRICT)
    if (NOT CMAKE_CXX_STANDARD)
        set(CMAKE_CXX_STANDARD 17)
    endif()

    set(CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF) # use -std=c++XX rather than -std=gnu++XX
endif()

message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# add_subdirectory(3rdparty)
include(${CMAKE_CURRENT_LIST_DIR}/library.cmake)

if (TIETON__BUILD_TESTS AND EXISTS ${CMAKE_CURRENT_LIST_DIR}/tests)
    enable_testing()
    add_subdirectory(tests)
endif()

if (TIETON__BUILD_DEMO AND EXISTS ${CMAKE_CURRENT_LIST_DIR}/demo)
    add_subdirectory(demo)
endif()

