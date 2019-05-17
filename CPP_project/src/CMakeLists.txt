cmake_minimum_required(VERSION 2.8)

project(PikiFamsGame)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)

set(PIKIFAMS_APP_SOURCES

    #----------PikiFamsGame-------#

    gamebot.cpp
    gamebot.h

    GameCreator.cpp
    GameCreator.h

    #----------LipaboyLib-------#
    lipaboyLibrary/src/intervals/interval.h
    lipaboyLibrary/src/intervals/cutoffborders.h
    lipaboyLibrary/src/common_interfaces/comparable.h
)

# Declare the library
add_library(PIKIFAMS_LIB STATIC
    ${PIKIFAMS_APP_SOURCES}
)


# Specify here the include directories exported
# by this library
target_include_directories(PIKIFAMS_LIB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
