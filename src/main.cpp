#include "game.hpp"  
#include "window_manager.hpp"
#include <raylib.hpp>
#include <iostream>
//C:\Users\Reg\Desktop\competitive-pong\src

int main()
{
    WindowManager window = WindowManager(1366, 768, "bouncing-ball");
     
    Game game = Game();
    
    while (!WindowShouldClose())
    {
        if (IsWindowResized())
        {
            window.ManageWindowResizing(GetScreenWidth(), GetScreenHeight());   // Gère la redimention de la fenetre de jeu
            game.Reset();
        }
        // Toggle full screen if f key pressed
        if(IsKeyPressed(KEY_F)) {
            window.ManageFullScreen();
            game.Reset();
        }

        game.Update();
        game.Render();
    }
    CloseWindow();
    return 0;
}
