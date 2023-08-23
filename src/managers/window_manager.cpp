#include "Window_manager.hpp"
#include "globals.hpp"
#include <iostream>


WindowManager::WindowManager(int width, int height, const char* title) 
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title);
    SetWindowState(FLAG_VSYNC_HINT);
    GAME_WIDTH = WINDOW_WIDTH;
    GAME_HEIGHT = WINDOW_HEIGHT;
    MARGIN_X = 0;
    MARGIN_Y = 0;
}

WindowManager::~WindowManager() {
    CloseWindow();
}


// === Accessors ===
int WindowManager::GetWidth() {
    return GetScreenWidth();
}

int WindowManager::GetHeight() {
    return GetScreenHeight();
}

bool WindowManager::WindowShouldClose() {
    return ::WindowShouldClose();
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
    if(IsWindowFullscreen())
    {
        ToggleFullScreen();
        SetWindowSize(1366, 768);
        ManageWindowResizing(1366, 768);   // Gère la redimention de la fenetre de jeu
    }
    else
    {
        SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
        ManageWindowResizing(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));    // Gère la redimention de la fenetre de jeu
        ToggleFullScreen();
    }
}


// === Mutators ===
void WindowManager::ToggleFullScreen() {
    ::ToggleFullscreen();
}


// === Rendering ===
void WindowManager::BeginDrawing() {
    ::BeginDrawing();
}

void WindowManager::EndDrawing() {
    ::EndDrawing();
}