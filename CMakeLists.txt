cmake_minimum_required(VERSION 3.20)
project(console_calc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-static")

add_executable(console_calc main.cpp equation.cpp equation.h help.cpp help.h cli.cpp cli.h)
