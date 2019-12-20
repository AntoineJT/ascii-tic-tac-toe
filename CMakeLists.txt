# cmake_minimum_required(VERSION <specify CMake version here>)
project(ascii_tic_tac_toe C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(ascii_tic_tac_toe
        src/boolean.h
        src/main.c)
