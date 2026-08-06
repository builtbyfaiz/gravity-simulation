#include "renderer.h"

#include <string>
#include <vector>
#include <iostream>

// Render world
void Renderer::render()
{

    if (world.camMode)
        camera.Update(CAMERA_FREE);

    BeginDrawing();
    ClearBackground(BLACK);

    camera.BeginMode();

    DrawGrid(30, 1.0f);
    
    for (auto &planet : world.bodies)
    {
        renderPosition = planet.position * world.renderScale;
        renderRadius.x = planet.radius   * world.renderScale * world.planetScale;

        renderRadius.y = renderRadius.x;
        renderRadius.z = renderRadius.x;

        // planet.model.transform = MatrixScale(renderRadius.x, renderRadius.y, renderRadius.z);

        DrawModelEx     (planet.model, renderPosition, {0, 1, 0}, 0.0, renderRadius, planet.color);
        DrawModelWiresEx(planet.model, renderPosition, {0, 1, 0}, 0.0, renderRadius, WHITE); 

        std::cout << "Px:" << renderPosition.x << "\n";
        std::cout << "Py:" << renderPosition.y << "\n";
        std::cout << "Pz:" << renderPosition.z << "\n\n";
        std::cout << "Rx:" << renderRadius.x   << "\n";
        std::cout << "Ry:" << renderRadius.y   << "\n";
        std::cout << "Rz:" << renderRadius.z   << "\n";
    }

    camera.EndMode();

    DrawFPS(10, 10);
    std::string massText, positionText, velocityText, accelerationText;

    massText         = "Mass: "        + std::to_string(world.getSelected().mass);
    positionText     = "Position: "    + toString(world.getSelected().position);
    velocityText     = "Velocity: "    + toString(world.getSelected().velocity);
    accelerationText = "Aceleration: " + toString(world.getSelected().acceleration);

    Font mono = LoadFontEx("C:/Windows/Fonts/consola.ttf", 20, 0, 0);
    
    DrawTextEx(mono, massText.c_str(),         {10,  30}, 20, 5, RED);
    DrawTextEx(mono, positionText.c_str(),     {10,  55}, 20, 5, RED);
    DrawTextEx(mono, velocityText.c_str(),     {10,  80}, 20, 5, RED);
    DrawTextEx(mono, accelerationText.c_str(), {10, 105}, 20, 5, RED);

    EndDrawing();
}

std::string Renderer::toString(const raylib::Vector3& v)
{
    // Full Numbers
    std::string x = std::to_string(v.x); 
    std::string y = std::to_string(v.y);
    std::string z = std::to_string(v.z);

    // std::string sx, sy, sz; // Empty Shells to then store trunctuated Numbers

    // sx += x[0];
    // sx += x[1];
    // sx += x[2];
    // sx += x[3];

    // sy += y[0];
    // sy += y[1];
    // sy += y[2];
    // sy += y[3];

    // sz += z[0];
    // sz += z[1];
    // sz += z[2];
    // sz += z[3];

    return x + ", " + y + ", " + z;
}
