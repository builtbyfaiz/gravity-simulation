#include "simulator.h"

void Simulator::simulate()
{
    float dt = GetFrameTime() * world.simulationScale;

    for (auto& planet : world.bodies)
    {
        planet.acceleration = (raylib::Vector3){0.0, 0.0, 0.0};

        for (auto& other : world.bodies)
        {
            if (&planet == &other) continue;

            raylib::Vector3 displacement = other.position - planet.position;
            float           distance     = displacement.Length();

            // Avoid division by zero
            if (distance < 0.001)
                continue;

            // Gravitational acceleration = r hat * constant-G * m2/r^2
            planet.acceleration += displacement.Normalize() * (G * (other.mass / (distance * distance)));
        }
    }

    for (auto &planet : world.bodies)
    {
        planet.velocity += planet.acceleration * dt;
        planet.position += planet.velocity     * dt; 
    }
}