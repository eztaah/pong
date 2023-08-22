int main()
{
    WindowManager window = WindowManager(1366, 768, "bouncing-ball");
    int stateGame(1); // le State_Manager du clochard
    int currentImageIndex(0);
    Game game = Game();
    
    const char* imagePaths[] = 
    {
        "main_menu_1.png",
        "main_menu_2.png",
        "main_menu_3.png",
        "main_menu_4.png"
    };

    Texture2D images[4];
    for (int i = 0; i < 4; ++i)
    {
        images[i] = LoadTexture(imagePaths[i]);
    }
    
    if (stateGame == 1)
    {
        if (IsKeyPressed(KEY_UP))
        {
             currentImageIndex = (currentImageIndex - 1 + 4) % 4;
        }
        else if (IsKeyPressed(KEY_DOWN))
        {           
           currentImageIndex = (currentImageIndex + 1) % 4;
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            if (currentImageIndex == 0)
            stateGame = 2;
        }
    }
