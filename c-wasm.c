#include"raylib.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

int playerX = WIDTH / 2;
int playerY = HEIGHT / 2;
const int playerSIZE = WIDTH / 20;
const int randomRectNumber = 40;

struct Obj
{
    bool turnX;
    bool turnY;
    Rectangle rect;
};

struct Obj obj[40];

void GameInit()
{
    InitWindow(WIDTH, HEIGHT, "Raylib C-WASM");
    SetTargetFPS(60);

    for (int i = 0; i < randomRectNumber; i++)
    {
        obj[i].rect.x = i * 10;
        obj[i].rect.y = i * 10;
        obj[i].rect.width = 20;
        obj[i].rect.height = 20;
        obj[i].turnY = false;
        obj[i].turnX = false;
    }
}

void GameFrame()
{
    BeginDrawing();
    ClearBackground(BLACK);

    if (IsKeyDown(KEY_A))
        playerX--;
    if (IsKeyDown(KEY_D))
        playerX++;
    if (IsKeyDown(KEY_W))
        playerY--;
    if (IsKeyDown(KEY_S))
        playerY++;


    for (int i = 0; i < randomRectNumber; i++)
    {
        float idx = i;
        int r = (idx / randomRectNumber) * 255;
        int g = (idx / randomRectNumber)*(idx / randomRectNumber) * 255;
        int b = (idx / randomRectNumber)*(idx / randomRectNumber)*(idx / randomRectNumber) * 255;
        int a = 255;

        Color color = {r,g,b,a};

        if (obj[i].rect.x < 0)
            obj[i].turnX = true;
        if (obj[i].rect.x > WIDTH)
            obj[i].turnX = false;

        if (obj[i].rect.y < 0)
            obj[i].turnY = true;
        if (obj[i].rect.y > HEIGHT)
            obj[i].turnY = false;

        if (obj[i].turnX)
            obj[i].rect.x+= 1 * (int)(idx * 0.5);
        else
            obj[i].rect.x-= 1 * (int)(idx * 0.5);

        if (obj[i].turnY)
            obj[i].rect.y+= 1 * (int)(idx * 0.5);
        else
            obj[i].rect.y-= 1 * (int)(idx * 0.5);

        DrawRectangle(obj[i].rect.x, obj[i].rect.y, obj[i].rect.width, obj[i].rect.height, color);
    }

    DrawRectangle(playerX, playerY, playerSIZE, playerSIZE, RED);

    EndDrawing();
}

#ifndef PLATFORM_WEB
int main()
{
    GameInit();
    while (!WindowShouldClose())
    {   
        GameFrame();
    }
    CloseWindow();
    return 0;
}
#endif
