#include "Render.h"

void drawStroke(const std::vector<drawn>& stroke) {
    for (const auto& circle : stroke) {
        DrawCircleV(circle.pos, circle.r, circle.color);
    }
}

Vector2 MDownStroke(Vector2 prevPos, Vector2 ballPos, Color ballColor, std::vector<drawn>& currentStroke)
{
    float distance = Vector2Distance(prevPos, ballPos);
    if (distance > 1.0f) {
        int steps = (int)(distance / 2.0f);
        for (int i = 0; i < steps; i++) {
            float t = (float)i / steps;
            Vector2 interpPos = Vector2Lerp(prevPos, ballPos, t);
            drawn interpolatedCircle = { interpPos, ballColor, 5 };
            currentStroke.push_back(interpolatedCircle);
        }
    }
    drawn finalCircle = { ballPos, ballColor, 5 };
    currentStroke.push_back(finalCircle);
    prevPos = ballPos;
    return prevPos;
}

void addCurrStroke(RenderTexture& renderTexture, std::vector<drawn>& currentStroke, std::vector<std::vector<drawn>>& strokes) {
    BeginTextureMode(renderTexture);
    drawStroke(currentStroke);
    EndTextureMode();
    strokes.push_back(currentStroke);
    currentStroke.clear();
}



