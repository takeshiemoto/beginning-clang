cmake_minimum_required(VERSION 3.27)
project(beginning-clang C)

set(CMAKE_C_STANDARD 11)

add_executable(beginning-clang main.c
        recursively.h
        recursively.c)
