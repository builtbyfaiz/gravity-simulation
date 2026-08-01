#pragma once
#include "body.h"
#include <vector>

class World {
public:
  std::vector<CelestialBody> bodies;

  void addBody(CelestialBody body);
};