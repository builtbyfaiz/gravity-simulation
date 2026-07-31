#pragma once
#include "model/world.h"

class Renderer {
    public:
    World world;
    Renderer::Renderer(World &w) : world(w) {};
};