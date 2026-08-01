#pragma once
#include "model/world.h"

class Renderer {
    public:
    World world;
    Renderer(World &w) : world(w) {};
};