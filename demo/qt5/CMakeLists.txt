################################################################################
# Copyright (c) 2024 Vladislav Trifochkin
#
# This file is part of `tieton-lib`.
#
# Changelog:
#      2024.08.26 Initial version.
################################################################################
project(qt5-demo CXX C)

if (TARGET pfs::tieton)
    set(_tieton_lib pfs::tieton)
elseif (TARGET pfs::tieton::static)
    set(_tieton_lib pfs::tieton::static)
else()
    message(FATAL_ERROR "No any tieton TARGET found")
endif()

portable_target(ADD_EXECUTABLE ${PROJECT_NAME})
portable_target(SOURCES ${PROJECT_NAME} main.cpp main.qrc)
portable_target(LINK ${PROJECT_NAME} PUBLIC ${_tieton_lib})
target_link_directories(${PROJECT_NAME} PUBLIC /path/to/openssl-1.1.1j) # FIXME
target_link_libraries(${PROJECT_NAME} PUBLIC crypto ssl)
portable_target(LINK_QT5_COMPONENTS ${PROJECT_NAME} Core Gui Qml Quick)
