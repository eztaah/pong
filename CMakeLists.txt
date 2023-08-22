cmake_minimum_required(VERSION 3.10)

# Project name
project(competitive-pong)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories, CMake will inform the compiler to also look in this directory when resolving #include directives.
include_directories(src)
include_directories(lib/raylib)
include_directories(src/core)    
include_directories(src/entities/include)
include_directories(src/managers)

# Link directories (where the .a or .lib files are located)
link_directories(lib/raylib)

# Source files 
set(SOURCE_FILES
    src/main.cpp

    src/globals.hpp
    src/globals.cpp

    src/core/game.hpp
    src/core/game.cpp

    src/entities/include/ball.hpp
    src/entities/src/ball.cpp
    src/entities/include/paddle.hpp
    src/entities/src/paddle.cpp

    src/managers/window_manager.hpp
    src/managers/window_manager.cpp
)

# Set the location of the exe file that will be created
add_executable(debug ${SOURCE_FILES})     # <- this is the target

# add dll files inside the executable
target_link_options(debug PRIVATE -static -static-libstdc++ -static-libgcc)

# Link to all the needed library
target_link_libraries(debug raylib opengl32 gdi32 winmm)

# compiler compiler flags 
target_compile_options(debug PRIVATE -Wall -Wextra)

#compiler linker flags
set_target_properties(debug PROPERTIES LINK_FLAGS "-mwindows")