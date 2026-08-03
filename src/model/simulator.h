#pragma once
#include "world.h"

class Simulator
{
  public:
    World &world;
    
    const float G = 6.67430e-11; // Gravitational Constant
    
    Simulator(World &w) : world(w) {}

    void simulate(); // Simulates gravitational forces between everything
};