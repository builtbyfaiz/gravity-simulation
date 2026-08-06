#pragma once
#include "body.h"

#include <vector>


class World
{
  public:
    int  selectedIndex = -1;

    // Application Settings, I don't know if I should store them inside world here.
    bool   camMode         = true;
    float  renderScale     = 1.0/30000000.0f;  // Scale astronomical distances down to the screen
    float  planetScale     = 1.0f;             // Exaggerate planets
    double simulationScale = 84600;            // At 84600, each IRL second = in-sim 1 Day

    std::vector<CelestialBody> bodies;

    void changeTarget();
    void toggleCamMode();
    void addBody(CelestialBody body);
    
    CelestialBody &getSelected(); // Returns reference to selected celestial body

    World() {}
};