cmake_minimum_required(VERSION 3.11)
project(ds C)

set(CMAKE_C_STANDARD 99)
include_directories(include)
add_subdirectory (src)
add_subdirectory (app)