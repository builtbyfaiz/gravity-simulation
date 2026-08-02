#include "simulator.h"

void Simulator::simulate()
{
    for (auto &planet : world.bodies)
    {
        planet.velocity += planet.acceleration;
        planet.position += planet.velocity; // 1 is gravity
    }
}