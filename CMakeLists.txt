cmake_minimum_required(VERSION 4.2.3)

project(3DGame)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(Dependencies.cmake)

add_subdirectory(Core)
add_subdirectory(App)
