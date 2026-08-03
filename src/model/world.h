#pragma once
#include "body.h"

#include <vector>


class World
{
  public:
    int  selectedIndex = -1;

    // Render Settings
    bool  camMode     = true;
    float renderScale = 1.0/20000000.0f;  // scale astronomical distances down to the screen
    float planetScale = 10.0f;            // exaggerate planets

    std::vector<CelestialBody> bodies;

    void changeTarget();
    void toggleCamMode();
    void addBody(CelestialBody body);
    
    CelestialBody &getSelected(); // Returns reference to selected celestial body

    World() {}
};