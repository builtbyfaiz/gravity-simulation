#pragma once
#include <world.h>

class Controller {
public:
  World &world;

  Controller(World &world) : world(world) {}

  void update();
};