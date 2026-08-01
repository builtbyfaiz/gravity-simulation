#include "renderer.h"

// Render world
void Renderer::render() {
    
    camera.Update(CAMERA_FREE);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    camera.BeginMode();

    DrawGrid(30, 1.0f);

    for (auto& planet : world.bodies) {
        DrawModel(planet.model, planet.position, planet.scale, planet.color);
        DrawModelWires(planet.model, planet.position, planet.scale, BLACK);
    }

    camera.EndMode();

    DrawFPS(10, 10);   
    EndDrawing();
}
