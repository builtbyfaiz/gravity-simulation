#include "renderer.h"

#include <string>
#include <vector>

// Render world
void Renderer::render()
{

    if (world.camMode)
        camera.Update(CAMERA_FREE);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    camera.BeginMode();

    DrawGrid(30, 1.0f);

    for (auto &planet : world.bodies)
    {
        DrawModel(planet.model, planet.position, planet.scale, planet.color);
        DrawModelWires(planet.model, planet.position, planet.scale, BLACK);
    }

    camera.EndMode();

    DrawFPS(10, 10);
    std::string massText, positionText, velocityText, accelerationText;

    massText         = "Mass: "        + std::to_string(world.getSelected().mass);
    positionText     = "Position: "    + toString(world.getSelected().position);
    velocityText     = "Velocity: "    + toString(world.getSelected().velocity);
    accelerationText = "Aceleration: " + toString(world.getSelected().acceleration);

    DrawText(massText.c_str(),         5,  30, 20, RED);
    DrawText(positionText.c_str(),     5,  55, 20, RED);
    DrawText(velocityText.c_str(),     5,  80, 20, RED);
    DrawText(accelerationText.c_str(), 5, 105, 20, RED);

    EndDrawing();
}

std::string Renderer::toString(const raylib::Vector3& v)
{
    // Full Numbers
    std::string x = std::to_string(v.x); 
    std::string y = std::to_string(v.y);
    std::string z = std::to_string(v.z);

    std::string sx, sy, sz; // Empty Shells to then store trunctuated Numbers

    sx += x[0];
    sx += x[1];
    sx += x[2];
    sx += x[3];

    sy += y[0];
    sy += y[1];
    sy += y[2];
    sy += y[3];

    sz += z[0];
    sz += z[1];
    sz += z[2];
    sz += z[3];

    return sx + ", " + sy + ", " + sz;
}
