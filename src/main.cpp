#include "raylib-cpp.hpp"
#include "view/renderer.h"
#include "model/simulator.h"
#include "controller/controller.h"

int main() {
  raylib::Window window(1280, 800, "");
  SetTargetFPS(60);
  DisableCursor();

  CelestialBody planet;
  planet.model = LoadModelFromMesh(GenMeshSphere(2.0f, 16, 16)); 
  
  World world;
  world.addBody(planet);

  Renderer renderer(world);
  Simulator simulator(world);
  Controller controller(world);

  while (!window.ShouldClose()) {
    controller.update();
    simulator.simulate();
    renderer.render();  

    if(IsKeyPressed(KEY_ESCAPE)) EnableCursor();
  }

  return 0;
}