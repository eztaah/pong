#include "game.hpp"  
#include "window_manager.hpp"
#include "libs.hpp"


int main()
{
    WindowManager window = WindowManager(1366, 768, "bouncing-ball");
     
    Game game = Game();
    
    while (!rl::WindowShouldClose())
    {
        if (rl::IsWindowResized())
        {
            window.ManageWindowResizing(rl::GetScreenWidth(), rl::GetScreenHeight());   // Gère la redimention de la fenetre de jeu
            game.Reset();
        }
        // Toggle full screen if f key pressed
        if(rl::IsKeyPressed(rl::KEY_F)) 
        {
            window.ManageFullScreen();
            game.Reset();
        }

        game.Update();
        game.Render();
    }
    rl::CloseWindow();
    return 0;
}