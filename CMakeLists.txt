cmake_minimum_required(VERSION 3.10)

# Project name
project(competitive-pong)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories, CMake will inform the compiler to also look in this directory when resolving #include directives.
include_directories(src)
include_directories(lib)
include_directories(lib/my_raylib)
include_directories(lib/my_raylib/raylib)
include_directories(lib/interact_engine)
include_directories(src/core/include)
include_directories(src/states/include)    
include_directories(src/entities/include)
include_directories(src/managers)

# Link directories (where the .a or .lib files are located)
link_directories(lib/my_raylib/raylib)

# Source files 
set(SOURCE_FILES
    lib/libs.hpp
    lib/interact_engine/interact_engine.cpp
    lib/interact_engine/interact_engine.hpp
    lib/my_raylib/my_raylib.cpp
    lib/my_raylib/my_raylib.hpp

    src/main.cpp 
    src/globals.hpp 
    src/globals.cpp 

    src/core/include/Game.hpp
    src/core/src/Game.cpp
    src/core/include/GameState.hpp

    src/states/include/GameOverState.hpp
    src/states/src/GameOverState.cpp
    src/states/include/MenuState.hpp
    src/states/src/MenuState.cpp
    src/states/include/PlayingState.hpp
    src/states/src/PlayingState.cpp


    src/entities/include/Ball.hpp
    src/entities/src/Ball.cpp
    src/entities/include/Paddle.hpp
    src/entities/src/Paddle.cpp

    src/managers/WindowManager.hpp
    src/managers/WindowManager.cpp
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
