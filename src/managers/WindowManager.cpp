#include "Window_manager.hpp"
#include "globals.hpp"
#include "libs.hpp"
#include <iostream>


WindowManager::WindowManager(int width, int height, const char* title) 
{
    rl::SetConfigFlags(rl::FLAG_WINDOW_RESIZABLE);
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
    rl::InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title);
    rl::SetWindowState(rl::FLAG_VSYNC_HINT);
    GAME_WIDTH = WINDOW_WIDTH;
    GAME_HEIGHT = WINDOW_HEIGHT;
    MARGIN_X = 0;
    MARGIN_Y = 0;
}

WindowManager::~WindowManager() {
    rl::CloseWindow();
}


// === Logic ===
void WindowManager::ManageWindowResizing(int newWidth, int newHeight) {
    WINDOW_WIDTH = newWidth;
    WINDOW_HEIGHT = newHeight;

    // Calculate the maximum possible game area dimensions that fit the window while maintaining the aspect ratio
    GAME_WIDTH = WINDOW_WIDTH;
    GAME_HEIGHT = static_cast<int>(GAME_WIDTH / ASPECT_RATIO);

    if (GAME_HEIGHT > WINDOW_HEIGHT) {
        GAME_HEIGHT = WINDOW_HEIGHT;
        GAME_WIDTH = static_cast<int>(GAME_HEIGHT * ASPECT_RATIO);
    }

    // Calculate margins to center the game area in the window
    MARGIN_X = (WINDOW_WIDTH - GAME_WIDTH) / 2;
    MARGIN_Y = (WINDOW_HEIGHT - GAME_HEIGHT) / 2;
}

void WindowManager::ManageFullScreen()
{
    if(rl::IsWindowFullscreen())
    {
        rl::ToggleFullscreen();
        rl::SetWindowSize(1366, 768);
        ManageWindowResizing(1366, 768);   // Gère la redimention de la fenetre de jeu
    }
    else
    {
        int currentMonitor = rl::GetCurrentMonitor();
        int monitorWidth = rl::GetMonitorWidth(currentMonitor);
        int monitorHeight = rl::GetMonitorHeight(currentMonitor);
        
        rl::SetWindowSize(monitorWidth, monitorHeight);
        ManageWindowResizing(monitorWidth, monitorHeight);    // Gère la redimention de la fenetre de jeu
        rl::ToggleFullscreen();
    }
}
