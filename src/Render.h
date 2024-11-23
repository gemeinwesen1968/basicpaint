#pragma once

#include "../include/raylib.h"
#include "../include/raymath.h"
#include <vector>
#include <cstddef>

typedef struct {
    Vector2 pos;
    Color color;
    float r;
} drawn;


void drawStroke(const std::vector<drawn>& stroke);
Vector2 MDownStroke(Vector2 prevPos, Vector2 ballPos, Color ballColor, std::vector<drawn>& currentStroke, float strokeSize);
void addCurrStroke(RenderTexture& renderTexture, std::vector<drawn>& currentStroke, std::vector<std::vector<drawn>>& strokes);

