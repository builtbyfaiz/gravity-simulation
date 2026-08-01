#pragma once
#include "body.h"
#include <vector>

class World {
public:
  bool camMode = true;
  std::vector<CelestialBody> bodies;

  void toggleCamMode();

  void addBody(CelestialBody body);
  
};