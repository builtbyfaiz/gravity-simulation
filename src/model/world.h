#pragma once
#include "body.h"

#include <vector>


class World
{
  public:
    int  selectedIndex = -1;
    bool camMode       = true;

    std::vector<CelestialBody> bodies;

    void changeTarget();
    void toggleCamMode();
    void addBody(CelestialBody body);
    
    CelestialBody &getSelected(); // Returns reference to selected celestial body

    World() {}
};