cmake_minimum_required(VERSION 3.21)
project(cwk1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cwk1
        book_mangement.h
        main.c
        register.c
        register.h)
