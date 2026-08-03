#pragma once
#include "world.h"

class Simulator
{
  public:
    World &world;
    
    Simulator(World &w) : world(w) {}

    void simulate(); // Simulates gravitational forces between everything
};