cmake_minimum_required(VERSION 2.8)

project(PikiFamsGame)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)

set(APP_SOURCES

    #----------PikiFamsGame-------#
    src/gamebot.cpp
    src/gamebot.h

    src/GameCreator.cpp
    src/GameCreator.h

    src/main.cpp

    #----------LipaboyLib-------#
    src/lipaboyLibrary/src/intervals/interval.h
    src/lipaboyLibrary/src/intervals/cutoffborders.h
    src/lipaboyLibrary/src/common_interfaces/comparable.h
)

add_executable(PikiFamsGameApp ${APP_SOURCES})



