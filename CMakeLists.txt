cmake_minimum_required(VERSION 4.3)
project(lash)

set(CMAKE_CXX_STANDARD 20)

add_executable(lash
        main.cpp
        impl/console.cpp
        impl/prompt.cpp
        impl/commandmanager.cpp
        impl/cd_command.cpp
        impl/cd_command.h
)
