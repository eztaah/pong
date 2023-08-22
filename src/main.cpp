#include "game.hpp"  
#include "window_manager.hpp"
#include <raylib.hpp>
#include <iostream>


int main()
{
    WindowManager window = WindowManager(1366, 768, "bouncing-ball");
     
    Game game = Game();
    
    while (!WindowShouldClose())
    {
        if (IsWindowResized())
        {
            std::cout << "window resized " << std::endl;
            window.ManageWindowResizing(GetScreenWidth(), GetScreenHeight());   // Gère la redimention de la fenetre de jeu
            game.Reset();
        }
        // Toggle full screen if f key pressed
        if(IsKeyPressed(KEY_F)) {
            std::cout << GetMonitorWidth(0) << std::endl;
            std::cout << GetMonitorHeight(0) << std::endl;
            
            SetWindowSize(GetMonitorWidth(0), GetMonitorHeight(0));
            window.ManageWindowResizing(GetMonitorWidth(0), GetMonitorHeight(0));   // Gère la redimention de la fenetre de jeu
            window.ToggleFullScreen();
            game.Reset();
        }

        game.Update();
        game.Render();
    }
    CloseWindow();
    return 0;
}
