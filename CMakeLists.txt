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
include_directories(src/core)
include_directories(src/core/game_states)    
include_directories(src/entities)
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

    src/core/Game.hpp
    src/core/Game.cpp
    src/core/GameState.hpp

    src/entities/Ball.hpp
    src/entities/Ball.cpp
    src/entities/Paddle.hpp
    src/entities/Paddle.cpp
    src/entities/BotPaddle.hpp
    src/entities/BotPaddle.cpp   

    src/core/game_states/GameOverState.hpp
    src/core/game_states/GameOverState.cpp
    src/core/game_states/MenuState.hpp
    src/core/game_states/MenuState.cpp
    src/core/game_states/PlayingState.hpp
    src/core/game_states/PlayingState.cpp

    src/managers/WindowManager.hpp
    src/managers/WindowManager.cpp
    src/managers/AudioManager.hpp
    src/managers/AudioManager.cpp
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
