#include "world.h"

#include <iostream>


void World::toggleCamMode()
{
    camMode = camMode ? false : true;
    std::cout << camMode;
}

// Adds a celestial body to the world
void World::addBody(CelestialBody body)
{
    bodies.push_back(body);
    selectedIndex++;
}

CelestialBody &World::getSelected() { return bodies[selectedIndex]; }
