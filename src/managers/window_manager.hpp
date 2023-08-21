#include <raylib.hpp>


class WindowManager {
public:
    WindowManager(int width, int height, const char* title);
    ~WindowManager();

    // === Accessors ===
    int GetWidth();
    int GetHeight();
    bool WindowShouldClose();

    // === Mutators ===
    void ManageWindowResizing(int newWidth, int newHeight);
    void ToggleFullScreen();
    
    // === Rendering ===
    void BeginDrawing();
    void EndDrawing();
};
