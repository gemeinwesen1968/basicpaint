#include <vector>
#include "../include/raylib.h"
#include "ColorSelectMenu.h"
#include "Render.h"


//TODO create a layer class
//TODO create a input handler class
//TODO create a texture handler class
//TODO when slow, lines look seperate

int main()
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "PAINT");
    Color ballColor = BLACK;
    ColorSelectMenu colorMenu;
    SetTargetFPS(120);

    std::vector<std::vector<drawn>> strokes; 
    std::vector<drawn> currentStroke;  

    Vector2 previousPos = GetMousePosition();

    float size = 5;

    RenderTexture2D renderTexture = LoadRenderTexture(screenWidth, screenHeight);
    BeginTextureMode(renderTexture);
    ClearBackground(RAYWHITE);
    EndTextureMode();

    while (!WindowShouldClose())
    {
        const Vector2 ballPos = GetMousePosition();
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            previousPos = MDownStroke(previousPos, ballPos, ballColor, currentStroke, size);
        }
        else {
            previousPos = ballPos;
            if (!currentStroke.empty()) {
                addCurrStroke(renderTexture, currentStroke, strokes);
            }
        }

        if (IsKeyPressed(KEY_Z) && !strokes.empty()) {
            strokes.pop_back();

            BeginTextureMode(renderTexture);
            ClearBackground(RAYWHITE);
            for (const auto& stroke : strokes) {
                drawStroke(stroke);
            }
            EndTextureMode();
        }
        
        if (IsKeyPressed(KEY_X)) {
            strokes.clear();
            BeginTextureMode(renderTexture);
            ClearBackground(RAYWHITE);
            EndTextureMode();
        }

        if (IsKeyPressed(KEY_R)) {
            ballColor = RED;
        }

        if (IsKeyPressed(KEY_G)) {
            ballColor = GREEN;
        }

        if (IsKeyPressed(KEY_B)) {
            ballColor = BLUE;
        }

        if (IsKeyPressed(KEY_F)) {
            ballColor = BLACK;
        }
        
        if (IsKeyPressed(KEY_A)) {
            size = size + 0.2f;
        }

        if (IsKeyPressed(KEY_S)) {
            size = size - 0.2f;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureRec(renderTexture.texture, { 0, 0, (float)renderTexture.texture.width, (float)-renderTexture.texture.height }, { 0, 0 }, WHITE);
        drawStroke(currentStroke);

        DrawCircleV(ballPos, size, ballColor);
        colorMenu.draw();

        int fps = GetFPS();
        DrawText(TextFormat("%i", fps), 700, 0, 30, PINK);

        EndDrawing();
    }
    UnloadRenderTexture(renderTexture);
    CloseWindow();
    return 0;
}
