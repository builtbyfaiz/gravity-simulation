#include "simulator.h"

void Simulator::simulate() {
    for (auto &planet : world.bodies)
    {
        planet.position += planet.velocity; // 1 is gravity
    }
    
}