#include "Game.hpp"  
#include "WindowManager.hpp"
#include "libs.hpp"


int main()
{
    WindowManager window = WindowManager(1366, 768, "bouncing-ball");

    Game game = Game(window);
    
    while (!rl::WindowShouldClose())
    {
        if (rl::IsWindowResized())
        {
            window.ManageWindowResizing(rl::GetScreenWidth(), rl::GetScreenHeight());   // Gère la redimention de la fenetre de jeu
            game.SetMenuState();
        }
        // Plein écran en appuiant sur "F"
        if(rl::IsKeyPressed(rl::KEY_F)) 
        {
            window.ManageFullScreen();
            game.SetMenuState();
        }
        game.Update();
        game.Render();
    }

    rl::CloseWindow();
    return 0;
}