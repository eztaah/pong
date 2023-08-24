#include "Game.hpp"  
#include "WindowManager.hpp"
#include "libs.hpp"
#include "raylib.hpp"


int main()
{
    WindowManager window = WindowManager(1366, 768, "bouncing-ball");

    // === Music ===
    InitAudioDevice();  
    Sound backgroundMusic = LoadSound("../assets/sounds/music.mp3");
    PlaySound(backgroundMusic);


    Game game = Game();
    
    while (!rl::WindowShouldClose())
    {
        if (rl::IsWindowResized())
        {
            window.ManageWindowResizing(rl::GetScreenWidth(), rl::GetScreenHeight());   // Gère la redimention de la fenetre de jeu
            game.Reset();
        }
        // Plein écran en appuiant sur "F"
        if(rl::IsKeyPressed(rl::KEY_F)) 
        {
            window.ManageFullScreen();
            game.Reset();
        }
        game.Update();
        game.Render();
    }

    UnloadSound(backgroundMusic);
    CloseAudioDevice();  
    
    rl::CloseWindow();
    return 0;
}