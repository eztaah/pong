#include "game.hpp"
#include <raylib.hpp>
#include <iostream>


int main()
{
    InitWindow(1366, 768, "COMPETITIVE PONG");
    SetWindowState(FLAG_VSYNC_HINT);
    
    Game game = Game();
    
    while (!WindowShouldClose())
    {
        game.Update();
        game.Render();
    }
    CloseWindow();
    return 0;
}