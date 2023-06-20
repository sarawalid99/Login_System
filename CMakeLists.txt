cmake_minimum_required(VERSION 3.25)
project(Login_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Login_System
        LoginApp.cpp
        LoginFunctions.cpp
        LoginFunctions.h)
