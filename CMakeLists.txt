cmake_minimum_required(VERSION 3.2)

project(pong VERSION 1.0)

file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories(include)

add_executable(pong ${SOURCES})

target_link_directories(pong PRIVATE lib)

target_link_libraries(pong PRIVATE raylib Winmm)
