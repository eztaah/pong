cmake_minimum_required(VERSION 3.2)

project(pong VERSION 1.0)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(pong ${SOURCES})
