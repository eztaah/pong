cmake_minimum_required(VERSION 3.10)

# Project name
project(competitive-pong) 

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories, CMake will inform the compiler to also look in this directory when resolving #include directives.
include_directories(src)
include_directories(src/lib)
include_directories(src/lib/my_raylib)
include_directories(src/lib/my_raylib/raylib)
include_directories(src/lib/interact_engine)
include_directories(src/core)
include_directories(src/core/game_states)    
include_directories(src/entities)
include_directories(src/managers)

# Link directories (where the .a or .lib files are located)
link_directories(src/lib/my_raylib/raylib)

# Source files 
set(SOURCE_FILES
    src/lib/libs.hpp
    src/lib/interact_engine/interact_engine.cpp
    src/lib/interact_engine/interact_engine.hpp
    src/lib/my_raylib/my_raylib.cpp
    src/lib/my_raylib/my_raylib.hpp

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


##############

# Spécifiez où les binaires doivent être créés
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# Set compiler options for Debug build
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Indique quels sont les fichiers à compiler
    add_executable(debug ${SOURCE_FILES})     # <- this is the target

    # add dll files inside the executable
    target_link_options(debug PRIVATE -static -static-libstdc++ -static-libgcc)

    target_compile_options(debug PRIVATE -Wall -Wextra -g)
    # -g: Cela permet au débogueur de montrer des valeurs de variable, de naviguer dans le code source.

    # Relie les différentes libraries à l'executable
    target_link_libraries(debug raylib opengl32 gdi32 winmm)


endif()


#RELEASE
#compiler linker flags
# set_target_properties(debug PROPERTIES LINK_FLAGS "-mwindows")