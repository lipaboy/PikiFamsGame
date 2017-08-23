cmake_minimum_required(VERSION 2.8)

project(PikiFamsGame)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)

#find_package(Qt5Core)

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

#target_link_libraries(PikiFamsGameApp  Qt5::Core)

#add_custom_command(
#                TARGET PikiFamsGameApp  POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy_if_different
#                        $<TARGET_FILE:Qt5::Core>)


