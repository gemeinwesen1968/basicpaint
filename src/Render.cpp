#include "Render.h"


void drawStroke(const std::vector<drawn>& stroke) {
    for (size_t i = 1; i < stroke.size(); i++) {
        DrawLineEx(stroke[i - 1].pos, stroke[i].pos, stroke[i].r * 2, stroke[i].color);
    }
}

Vector2 MDownStroke(Vector2 prevPos, Vector2 currentPos, Color strokeColor, std::vector<drawn>& currentStroke, float strokeSize)
{
    float distance = Vector2Distance(prevPos, currentPos);
    float maxGap = 1.0f;  // Adjust gap based on stroke size

    if (distance > maxGap) {
        int steps = (int)(distance / maxGap);
        for (int i = 1; i <= steps; i++) {
            float t = (float)i / steps;
            Vector2 interpPos = Vector2Lerp(prevPos, currentPos, t);
            currentStroke.push_back({ interpPos, strokeColor, strokeSize / 2 });
        }
    }
    currentStroke.push_back({ currentPos, strokeColor, strokeSize / 2 });

    return currentPos;
}

void addCurrStroke(RenderTexture& renderTexture, std::vector<drawn>& currentStroke, std::vector<std::vector<drawn>>& strokes) {
    BeginTextureMode(renderTexture);
    drawStroke(currentStroke);
    EndTextureMode();
    strokes.push_back(currentStroke);
    currentStroke.clear();
}