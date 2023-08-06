#include <iostream>
#include <raylib.h>
#include "../include/Game.hpp"

int main()
{
    
    Game game = Game();
    
    while (!WindowShouldClose())
    {
        game.Update();
        game.Draw();
    }
    
    CloseWindow();
    return 0;
}