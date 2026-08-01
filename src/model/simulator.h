#pragma once
#include "world.h"

class Simulator {
public:
  World &world;

  Simulator(World &world) : world(world) {}

  void simulate(); // Simulates gravitational forces between everything
};