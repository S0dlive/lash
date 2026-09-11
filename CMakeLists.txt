cmake_minimum_required(VERSION 4.3)
project(lash)

set(CMAKE_CXX_STANDARD 20)

add_executable(lash main.cpp
        impl/console.cpp
        impl/console.h
        impl/prompt.cpp
        impl/prompt.h
        impl/command.cpp
        impl/command.h
        impl/commandmanager.cpp
        impl/commandmanager.h
)
