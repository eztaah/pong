#include "globals.hpp"
#include "my_raylib.hpp"
#include "raylib.hpp"


Vector2 ConvertToRaylib(const rl::Vector2& vector) {
    Vector2 result;
    result.x = vector.x;
    result.y = vector.y;
    return result;
}
Color ConvertToRaylib(const rl::Color& color) {
    Color result;
    result.r = color.r;
    result.g = color.g;
    result.b = color.b;
    result.a = color.a;
    return result;
}
Rectangle ConvertToRaylib(const rl::Rectangle& rectangle) {
    Rectangle result;
    result.x = rectangle.x;
    result.y = rectangle.y;
    result.width = rectangle.width;
    result.height = rectangle.height;
    return result;
}
Texture2D ConvertToRaylib(const rl::Texture2D& texture) {
    Texture2D result;
    result.id = texture.id;
    result.width = texture.width;
    result.height = texture.height;
    result.mipmaps = texture.mipmaps;
    result.format = texture.format;
    return result;
}
rl::Texture2D ConvertFromRaylib(const Texture2D& texture) {
    rl::Texture2D result;
    result.id = texture.id;
    result.width = texture.width;
    result.height = texture.height;
    result.mipmaps = texture.mipmaps;
    result.format = texture.format;
    return result;
}




// ===== RAYLIB LIBRARY =====

// === Window-related-functions ===
void rl::InitWindow(int width, int height, const char* title) {
    ::InitWindow(width, height, title);
}

bool rl::WindowShouldClose() {
    return ::WindowShouldClose();
}

void rl::CloseWindow() {
    ::CloseWindow();
}

bool rl::IsWindowFullscreen() {
    return ::IsWindowFullscreen();
}

void rl::ToggleFullscreen() {
    ::ToggleFullscreen();
}

void rl::SetWindowSize(int width, int height) {
    ::SetWindowSize(width, height);
}

bool rl::IsWindowResized() {
    return ::IsWindowResized();
}

void rl::SetWindowState(unsigned int flags) {
    ::SetWindowState(flags);
}

int rl::GetScreenWidth() {
    return ::GetScreenWidth();
}

int rl::GetScreenHeight() {
    return ::GetScreenHeight();
}

int rl::GetCurrentMonitor() {
    return ::GetCurrentMonitor();
}

int rl::GetMonitorWidth(int monitor) {
    return ::GetMonitorWidth(monitor);
}

int rl::GetMonitorHeight(int monitor) {
    return ::GetMonitorHeight(monitor);
}


// === Drawing-related functions ===
void rl::ClearBackground(rl::Color color) {
    ::ClearBackground(ConvertToRaylib(color));
}

void rl::BeginDrawing() {
    ::BeginDrawing();
}

void rl::EndDrawing() {
    ::EndDrawing();
}

void rl::DrawRectangle(int posX, int posY, int width, int height, rl::Color color) {
    ::DrawRectangle(MARGIN_X + posX, MARGIN_Y + posY, width, height, ConvertToRaylib(color));
}

void rl::BeginScissorMode(int x, int y, int width, int height) {
    ::BeginScissorMode(x, y, width, height);
}

void rl::EndScissorMode() {
    ::EndScissorMode();
}

void rl::DrawTextureEx(rl::Texture2D texture, rl::Vector2 position, float rotation, float scale, rl::Color tint) {
    rl::Vector2 positionWithMargins;
    positionWithMargins.x = MARGIN_X + position.x;
    positionWithMargins.y = MARGIN_Y + position.y;
    ::DrawTextureEx(ConvertToRaylib(texture), ConvertToRaylib(positionWithMargins), rotation, scale, ConvertToRaylib(tint));
}

void rl::DrawText(const char *text, int posX, int posY, int fontSize, rl::Color color) {
    ::DrawText(text, MARGIN_X + posX, MARGIN_Y + posY, fontSize, ConvertToRaylib(color));
}


// === Input-related functions: keyboard ===
bool rl::IsKeyPressed(int key) {
    return ::IsKeyPressed(key);
}

bool rl::IsKeyDown(int key) {
    return ::IsKeyDown(key);
}


// === Misc. functions ===
void rl::SetConfigFlags(unsigned int flags) {
    ::SetConfigFlags(flags);
}

bool rl::CheckCollisionRecs(rl::Rectangle rec1, rl::Rectangle rec2) {
    return ::CheckCollisionRecs(ConvertToRaylib(rec1), ConvertToRaylib(rec2));
}

rl::Texture2D rl::LoadTexture(const char *fileName) {
    return ConvertFromRaylib(::LoadTexture(fileName));
}

float rl::GetFrameTime() {
    return ::GetFrameTime();
}