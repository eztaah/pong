#include "iostream"
#include "raylib.h"
#include "Game.hpp"

int main()
{
    InitWindow(1366, 768, "PONG");
    SetWindowState(FLAG_VSYNC_HINT);
    
    Game game = Game();
    
    while (!WindowShouldClose())
    {
        game.Update();
        game.Draw();
    }
    CloseWindow();
    return 0;
}