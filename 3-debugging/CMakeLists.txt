cmake_minimum_required(VERSION 3.23)
project(3_debugging C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)

add_executable(3_debugging main.c)
target_link_libraries(3_debugging m)
