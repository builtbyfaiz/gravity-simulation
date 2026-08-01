#pragma once
#include "model/world.h"

class Controller {
public:
  World &world;

  Controller(World &w) : world(w) {}

  void update();
};