#include "renderer.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
        renderRadius.x = planet.radius * world.renderScale * world.planetScale;

        renderRadius.y = renderRadius.x;
        renderRadius.z = renderRadius.x;

        // planet.model.transform = MatrixScale(renderRadius.x, renderRadius.y, renderRadius.z);

        DrawModelEx(planet.model, renderPosition, {0, 1, 0}, 0.0, renderRadius, planet.color);
        DrawModelWiresEx(planet.model, renderPosition, {0, 1, 0}, 0.0, renderRadius, WHITE);

        std::cout << "Px:" << renderPosition.x << "\n";
        std::cout << "Py:" << renderPosition.y << "\n";
        std::cout << "Pz:" << renderPosition.z << "\n\n";
        std::cout << "Rx:" << renderRadius.x << "\n";
        std::cout << "Ry:" << renderRadius.y << "\n";
        std::cout << "Rz:" << renderRadius.z << "\n";
    }

    camera.EndMode();

    DrawFPS(10, 10);
    std::string massText, positionText, velocityText, accelerationText;

    massText = "Mass: " + std::to_string(world.getSelected().mass);
    positionText = "Position: " + toString(world.getSelected().position);
    velocityText = "Velocity: " + toString(world.getSelected().velocity);
    accelerationText = "Aceleration: " + toString(world.getSelected().acceleration);

    DrawTextEx(mono, massText.c_str(), {10, 30}, 20, 5, RED);
    DrawTextEx(mono, positionText.c_str(), {10, 55}, 20, 5, RED);
    DrawTextEx(mono, velocityText.c_str(), {10, 80}, 20, 5, RED);
    DrawTextEx(mono, accelerationText.c_str(), {10, 105}, 20, 5, RED);

    EndDrawing();
}

// Scientific formatting for large units.
std::string formatFloat(float value)
{
    if (value == 0.0f)
        return "0.00";

    float absValue = std::abs(value);

    if (absValue >= 1e6f || absValue < 1e-3f)
    {
        int exponent = static_cast<int>(std::floor(std::log10(absValue)));
        float mantissa = value / std::pow(10.0f, exponent);

        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2) << mantissa << "x10^" << exponent;

        return ss.str();
    }

    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << value;

    return ss.str();
}

std::string Renderer::toString(const raylib::Vector3 &v)
{
    return formatFloat(v.x) + ", " + formatFloat(v.y) + ", " + formatFloat(v.z);
}
