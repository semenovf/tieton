################################################################################
# Copyright (c) 2024 Vladislav Trifochkin
#
# This file is part of `tieton-lib`.
#
# Changelog:
#      2024.08.07 Initial version.
################################################################################
cmake_minimum_required (VERSION 3.11)
project(tieton LANGUAGES CXX C)

set(GEOSERVICES_PLUGIN_NAME qtgeoservices_${PROJECT_NAME})

option(TIETON__BUILD_SHARED "Enable build shared library" OFF)
option(TIETON__BUILD_STATIC "Enable build static library" ON)

if (NOT PORTABLE_TARGET__CURRENT_PROJECT_DIR)
    set(PORTABLE_TARGET__CURRENT_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
endif()

if (TIETON__BUILD_SHARED)
    portable_target(ADD_SHARED ${PROJECT_NAME} ALIAS pfs::tieton EXPORTS TIETON__EXPORTS)
    list(APPEND _tieton__targets ${PROJECT_NAME})
endif()

if (TIETON__BUILD_STATIC)
    set(STATIC_PROJECT_NAME ${PROJECT_NAME}-static)
    portable_target(ADD_STATIC ${STATIC_PROJECT_NAME} ALIAS pfs::tieton::static EXPORTS TIETON__STATIC)
    list(APPEND _tieton__targets ${PROJECT_NAME}-static)
endif()

portable_target(ADD_SHARED ${GEOSERVICES_PLUGIN_NAME} ALIAS pfs::tieton::geoservices EXPORTS TIETON__EXPORTS)

if (NOT TARGET pfs::common)
    portable_target(INCLUDE_PROJECT
        ${PORTABLE_TARGET__CURRENT_PROJECT_DIR}/2ndparty/common/library.cmake)
endif()

portable_target(SOURCES ${GEOSERVICES_PLUGIN_NAME}
    src/plugin/provider_factory.cpp src/plugin/provider_factory.hpp
    src/plugin/coding_manager_engine.cpp src/plugin/coding_manager_engine.hpp
    src/plugin/mapping_manager_engine.cpp src/plugin/mapping_manager_engine.hpp
    src/plugin/place_manager_engine.cpp src/plugin/place_manager_engine.hpp
    src/plugin/routing_manager_engine.cpp src/plugin/routing_manager_engine.hpp
    src/plugin/tile_fetcher.cpp src/plugin/tile_fetcher.hpp
    src/plugin/tiled_map.cpp src/plugin/tiled_map.hpp
    src/plugin/tiled_map_reply.cpp src/plugin/tiled_map_reply.hpp)

# FIXME Need another approach to set QT5_DIR
set(QT5_DIR "/home/wladt/Qt5.15.2-Desktop/5.15.2/gcc_64/lib/cmake/Qt5")

portable_target(LINK_QT5_COMPONENTS ${GEOSERVICES_PLUGIN_NAME} QT5_DIR ${QT5_DIR}
    REQUIRED
    PRIVATE Core Location Network Positioning)

portable_target(LINK ${GEOSERVICES_PLUGIN_NAME} PRIVATE Qt5::LocationPrivate pfs::common)

if (TARGET ${PROJECT_NAME})
    portable_target(LINK ${GEOSERVICES_PLUGIN_NAME} PRIVATE ${PROJECT_NAME})
else ()
    portable_target(LINK ${GEOSERVICES_PLUGIN_NAME} PRIVATE ${PROJECT_NAME}-static)
endif()

set_target_properties(${GEOSERVICES_PLUGIN_NAME}
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/geoservices)

list(APPEND _tieton__sources
    ${CMAKE_CURRENT_LIST_DIR}/src/dumb.cpp)

foreach(_target IN LISTS _tieton__targets)
    portable_target(SOURCES ${_target} ${_tieton__sources})
    portable_target(INCLUDE_DIRS ${_target}
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/include
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/include/pfs/tieton)
    portable_target(LINK ${_target} PUBLIC pfs::common)
endforeach()
