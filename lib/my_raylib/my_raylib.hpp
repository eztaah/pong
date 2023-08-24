#pragma once

namespace rl
{
    // Vector2, 2 components
    #define VECTOR2_DEFINED
    typedef struct Vector2 {    // typedef avoid the user to type "struct Vector2 vec{10.0f, 1.0f}""
        float x;                // Vector x component
        float y;                // Vector y component
    } Vector2;


    // Rectangle, 4 components
    #define RECTANGLE_DEFINED
    typedef struct Rectangle {
        float x;                // Rectangle top-left corner position x
        float y;                // Rectangle top-left corner position y
        float width;            // Rectangle width
        float height;           // Rectangle height
    } Rectangle;

    // Color, 4 components, R8G8B8A8 (32bit)
    #define COLOR_DEFINED
    typedef struct Color {
        unsigned char r;        // Color red value
        unsigned char g;        // Color green value
        unsigned char b;        // Color blue value
        unsigned char a;        // Color alpha value
    } Color;

    #define TEXTURE_DEFINED
    typedef struct Texture2D {
        unsigned int id;        // OpenGL texture id
        int width;              // Texture base width
        int height;             // Texture base height
        int mipmaps;            // Mipmap levels, 1 by default
        int format;             // Data format (PixelFormat type)
    } Texture2D;

    // Plain structures in C++ (without constructors) can be initialized with { }
    #if defined(__cplusplus)
        #define CLITERAL(type)      type
    #else
        #define CLITERAL(type)      (type)
    #endif

    #define LIGHTGRAY  CLITERAL(Color){ 200, 200, 200, 255 }   // Light Gray
    #define GRAY       CLITERAL(Color){ 130, 130, 130, 255 }   // Gray
    #define DARKGRAY   CLITERAL(Color){ 80, 80, 80, 255 }      // Dark Gray
    #define YELLOW     CLITERAL(Color){ 253, 249, 0, 255 }     // Yellow
    #define GOLD       CLITERAL(Color){ 255, 203, 0, 255 }     // Gold
    #define ORANGE     CLITERAL(Color){ 255, 161, 0, 255 }     // Orange
    #define PINK       CLITERAL(Color){ 255, 109, 194, 255 }   // Pink
    #define RED        CLITERAL(Color){ 230, 41, 55, 255 }     // Red
    #define MAROON     CLITERAL(Color){ 190, 33, 55, 255 }     // Maroon
    #define GREEN      CLITERAL(Color){ 0, 228, 48, 255 }      // Green
    #define LIME       CLITERAL(Color){ 0, 158, 47, 255 }      // Lime
    #define DARKGREEN  CLITERAL(Color){ 0, 117, 44, 255 }      // Dark Green
    #define SKYBLUE    CLITERAL(Color){ 102, 191, 255, 255 }   // Sky Blue
    #define BLUE       CLITERAL(Color){ 0, 121, 241, 255 }     // Blue
    #define DARKBLUE   CLITERAL(Color){ 0, 82, 172, 255 }      // Dark Blue
    #define PURPLE     CLITERAL(Color){ 200, 122, 255, 255 }   // Purple
    #define VIOLET     CLITERAL(Color){ 135, 60, 190, 255 }    // Violet
    #define DARKPURPLE CLITERAL(Color){ 112, 31, 126, 255 }    // Dark Purple
    #define BEIGE      CLITERAL(Color){ 211, 176, 131, 255 }   // Beige
    #define BROWN      CLITERAL(Color){ 127, 106, 79, 255 }    // Brown
    #define DARKBROWN  CLITERAL(Color){ 76, 63, 47, 255 }      // Dark Brown

    #define WHITE      CLITERAL(Color){ 255, 255, 255, 255 }   // White
    #define BLACK      CLITERAL(Color){ 0, 0, 0, 255 }         // Black
    #define BLANK      CLITERAL(Color){ 0, 0, 0, 0 }           // Blank (Transparent)
    #define MAGENTA    CLITERAL(Color){ 255, 0, 255, 255 }     // Magenta
    #define RAYWHITE   CLITERAL(Color){ 245, 245, 245, 255 }   // My own White (raylib logo)



    // System/Window config flags
    // NOTE: Every bit registers one state (use it with bit masks)
    // By default all flags are set to 0
    #define CONFIGFLAG_DEFINED
    typedef enum {
        FLAG_VSYNC_HINT         = 0x00000040,   // Set to try enabling V-Sync on GPU
        FLAG_FULLSCREEN_MODE    = 0x00000002,   // Set to run program in fullscreen
        FLAG_WINDOW_RESIZABLE   = 0x00000004,   // Set to allow resizable window
        FLAG_WINDOW_UNDECORATED = 0x00000008,   // Set to disable window decoration (frame and buttons)
        FLAG_WINDOW_HIDDEN      = 0x00000080,   // Set to hide window
        FLAG_WINDOW_MINIMIZED   = 0x00000200,   // Set to minimize window (iconify)
        FLAG_WINDOW_MAXIMIZED   = 0x00000400,   // Set to maximize window (expanded to monitor)
        FLAG_WINDOW_UNFOCUSED   = 0x00000800,   // Set to window non focused
        FLAG_WINDOW_TOPMOST     = 0x00001000,   // Set to window always on top
        FLAG_WINDOW_ALWAYS_RUN  = 0x00000100,   // Set to allow windows running while minimized
        FLAG_WINDOW_TRANSPARENT = 0x00000010,   // Set to allow transparent framebuffer
        FLAG_WINDOW_HIGHDPI     = 0x00002000,   // Set to support HighDPI
        FLAG_WINDOW_MOUSE_PASSTHROUGH = 0x00004000, // Set to support mouse passthrough, only supported when FLAG_WINDOW_UNDECORATED
        FLAG_MSAA_4X_HINT       = 0x00000020,   // Set to try enabling MSAA 4X
        FLAG_INTERLACED_HINT    = 0x00010000    // Set to try enabling interlaced video format (for V3D)
    } ConfigFlags;

    // Keyboard keys (US keyboard layout)
    // NOTE: Use GetKeyPressed() to allow redefining
    // required keys for alternative layouts
    
    typedef enum {
        KEY_NULL            = 0,        // Key: NULL, used for no key pressed
        // Alphanumeric keys
        KEY_APOSTROPHE      = 39,       // Key: '
        KEY_COMMA           = 44,       // Key: ,
        KEY_MINUS           = 45,       // Key: -
        KEY_PERIOD          = 46,       // Key: .
        KEY_SLASH           = 47,       // Key: /
        KEY_ZERO            = 48,       // Key: 0
        KEY_ONE             = 49,       // Key: 1
        KEY_TWO             = 50,       // Key: 2
        KEY_THREE           = 51,       // Key: 3
        KEY_FOUR            = 52,       // Key: 4
        KEY_FIVE            = 53,       // Key: 5
        KEY_SIX             = 54,       // Key: 6
        KEY_SEVEN           = 55,       // Key: 7
        KEY_EIGHT           = 56,       // Key: 8
        KEY_NINE            = 57,       // Key: 9
        KEY_SEMICOLON       = 59,       // Key: ;
        KEY_EQUAL           = 61,       // Key: =
        KEY_A               = 65,       // Key: A | a
        KEY_B               = 66,       // Key: B | b
        KEY_C               = 67,       // Key: C | c
        KEY_D               = 68,       // Key: D | d
        KEY_E               = 69,       // Key: E | e
        KEY_F               = 70,       // Key: F | f
        KEY_G               = 71,       // Key: G | g
        KEY_H               = 72,       // Key: H | h
        KEY_I               = 73,       // Key: I | i
        KEY_J               = 74,       // Key: J | j
        KEY_K               = 75,       // Key: K | k
        KEY_L               = 76,       // Key: L | l
        KEY_M               = 77,       // Key: M | m
        KEY_N               = 78,       // Key: N | n
        KEY_O               = 79,       // Key: O | o
        KEY_P               = 80,       // Key: P | p
        KEY_Q               = 81,       // Key: Q | q
        KEY_R               = 82,       // Key: R | r
        KEY_S               = 83,       // Key: S | s
        KEY_T               = 84,       // Key: T | t
        KEY_U               = 85,       // Key: U | u
        KEY_V               = 86,       // Key: V | v
        KEY_W               = 87,       // Key: W | w
        KEY_X               = 88,       // Key: X | x
        KEY_Y               = 89,       // Key: Y | y
        KEY_Z               = 90,       // Key: Z | z
        KEY_LEFT_BRACKET    = 91,       // Key: [
        KEY_BACKSLASH       = 92,       // Key: '\'
        KEY_RIGHT_BRACKET   = 93,       // Key: ]
        KEY_GRAVE           = 96,       // Key: `
        // Function keys
        KEY_SPACE           = 32,       // Key: Space
        KEY_ESCAPE          = 256,      // Key: Esc
        KEY_ENTER           = 257,      // Key: Enter
        KEY_TAB             = 258,      // Key: Tab
        KEY_BACKSPACE       = 259,      // Key: Backspace
        KEY_INSERT          = 260,      // Key: Ins
        KEY_DELETE          = 261,      // Key: Del
        KEY_RIGHT           = 262,      // Key: Cursor right
        KEY_LEFT            = 263,      // Key: Cursor left
        KEY_DOWN            = 264,      // Key: Cursor down
        KEY_UP              = 265,      // Key: Cursor up
        KEY_PAGE_UP         = 266,      // Key: Page up
        KEY_PAGE_DOWN       = 267,      // Key: Page down
        KEY_HOME            = 268,      // Key: Home
        KEY_END             = 269,      // Key: End
        KEY_CAPS_LOCK       = 280,      // Key: Caps lock
        KEY_SCROLL_LOCK     = 281,      // Key: Scroll down
        KEY_NUM_LOCK        = 282,      // Key: Num lock
        KEY_PRINT_SCREEN    = 283,      // Key: Print screen
        KEY_PAUSE           = 284,      // Key: Pause
        KEY_F1              = 290,      // Key: F1
        KEY_F2              = 291,      // Key: F2
        KEY_F3              = 292,      // Key: F3
        KEY_F4              = 293,      // Key: F4
        KEY_F5              = 294,      // Key: F5
        KEY_F6              = 295,      // Key: F6
        KEY_F7              = 296,      // Key: F7
        KEY_F8              = 297,      // Key: F8
        KEY_F9              = 298,      // Key: F9
        KEY_F10             = 299,      // Key: F10
        KEY_F11             = 300,      // Key: F11
        KEY_F12             = 301,      // Key: F12
        KEY_LEFT_SHIFT      = 340,      // Key: Shift left
        KEY_LEFT_CONTROL    = 341,      // Key: Control left
        KEY_LEFT_ALT        = 342,      // Key: Alt left
        KEY_LEFT_SUPER      = 343,      // Key: Super left
        KEY_RIGHT_SHIFT     = 344,      // Key: Shift right
        KEY_RIGHT_CONTROL   = 345,      // Key: Control right
        KEY_RIGHT_ALT       = 346,      // Key: Alt right
        KEY_RIGHT_SUPER     = 347,      // Key: Super right
        KEY_KB_MENU         = 348,      // Key: KB menu
        // Keypad keys
        KEY_KP_0            = 320,      // Key: Keypad 0
        KEY_KP_1            = 321,      // Key: Keypad 1
        KEY_KP_2            = 322,      // Key: Keypad 2
        KEY_KP_3            = 323,      // Key: Keypad 3
        KEY_KP_4            = 324,      // Key: Keypad 4
        KEY_KP_5            = 325,      // Key: Keypad 5
        KEY_KP_6            = 326,      // Key: Keypad 6
        KEY_KP_7            = 327,      // Key: Keypad 7
        KEY_KP_8            = 328,      // Key: Keypad 8
        KEY_KP_9            = 329,      // Key: Keypad 9
        KEY_KP_DECIMAL      = 330,      // Key: Keypad .
        KEY_KP_DIVIDE       = 331,      // Key: Keypad /
        KEY_KP_MULTIPLY     = 332,      // Key: Keypad *
        KEY_KP_SUBTRACT     = 333,      // Key: Keypad -
        KEY_KP_ADD          = 334,      // Key: Keypad +
        KEY_KP_ENTER        = 335,      // Key: Keypad Enter
        KEY_KP_EQUAL        = 336,      // Key: Keypad =
        // Android key buttons
        KEY_BACK            = 4,        // Key: Android back button
        KEY_MENU            = 82,       // Key: Android menu button
        KEY_VOLUME_UP       = 24,       // Key: Android volume up button
        KEY_VOLUME_DOWN     = 25        // Key: Android volume down button
    } KeyboardKey;



    // === Window-related-functions ===
    void InitWindow(int width, int height, const char *title);  // Initialize window and OpenGL context
    bool WindowShouldClose();                                   // Check if KEY_ESCAPE pressed or Close icon pressed
    void CloseWindow();                                         // Close window and unload OpenGL context
    bool IsWindowFullscreen();                                  // Check if window is currently fullscreen
    void ToggleFullscreen();                                    // Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
    void SetWindowSize(int width, int height);                  // Set window dimensions
    bool IsWindowResized();                                     // Check if window has been resized last frame
    void SetWindowState(unsigned int flags);                    // Set window configuration state using flags (only PLATFORM_DESKTOP)
    int GetScreenWidth();                                       // Get current screen width
    int GetScreenHeight();                                      // Get current screen height
    int GetCurrentMonitor();                                    // Get current connected monitor
    int GetMonitorWidth(int monitor);                           // Get specified monitor width (current video mode used by monitor)
    int GetMonitorHeight(int monitor);                          // Get specified monitor height (current video mode used by monitor)

    // === Drawing-related functions ===
    void ClearBackground(rl::Color color);                          // Set background color (framebuffer clear color)
    void BeginDrawing();                                        // Setup canvas (framebuffer) to start drawing
    void EndDrawing();                                          // End canvas drawing and swap buffers (double buffering)
    void DrawRectangle(int posX, int posY, int width, int height, rl::Color color); // Draw a color-filled rectangle
    void BeginScissorMode(int x, int y, int width, int height); // Begin scissor mode (define screen area for following drawing)
    void EndScissorMode();                                      // End scissor mode
    void DrawTextureEx(rl::Texture2D texture, rl::Vector2 position, float rotation, float scale, rl::Color tint);  // Draw a Texture2D with extended parameters
    void DrawText(const char *text, int posX, int posY, int fontSize, rl::Color color);       // Draw text (using default font)

    // === Input-related functions: keyboard ===
    bool IsKeyPressed(int key);                                 // Check if a key has been pressed once
    bool IsKeyDown(int key);                                    // Check if a key is being pressed

    // === Misc. functions ===
    void SetConfigFlags(unsigned int flags);                    // Setup init configuration flags (view FLAGS)
    bool CheckCollisionRecs(rl::Rectangle rec1, rl::Rectangle rec2);                                           // Check collision between two rectangles
    rl::Texture2D LoadTexture(const char *fileName);                                                       // Load texture from file into GPU memory (VRAM)
    float GetFrameTime();                                   // Get time in seconds for last frame drawn (delta time)
}
// ==========================================================================