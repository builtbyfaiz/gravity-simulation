#include "world.h"

// Adds a celestial body to the world
void World::addBody(CelestialBody body) 
{
    bodies.push_back(body);
}