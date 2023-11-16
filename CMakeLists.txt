cmake_minimum_required(VERSION 3.26)
project(u9 C)

set(CMAKE_C_STANDARD 11)

add_executable(u9 main.c
        circle.c
        circle.h
        rect.c
        rect.h)