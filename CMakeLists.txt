cmake_minimum_required(VERSION 3.10) # Minimum version of CMake

# Project name and version
project(List VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add executable
add_executable(List ./src/list.c)