#pragma once
#include "Render.h"
#include <string>
#include <vector>

//TODO: ADD LAYERS LIST TO RENDERER

typedef enum {
    active,
    locked,
} LayerType;

struct Layer{
    std::string name;
    float opacity;
    std::vector<std::vector<drawn>> strokes;
    RenderTexture2D texture;
    bool show;
    bool add;
    LayerType type;
};