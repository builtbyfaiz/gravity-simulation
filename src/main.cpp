#include "raylib-cpp.hpp"
#include "view/renderer.h"
#include "model/simulator.h"
#include "controller/controller.h"

int main() {
  
  // SetConfigFlags(FLAG_MSAA_4X_HINT);
  raylib::Window window(1280, 800, "Gravity Simulation", FLAG_VSYNC_HINT);
  
  SetTargetFPS(60);
  DisableCursor();
  
  World world;

  Renderer renderer(world);
  Simulator simulator(world);
  Controller controller(world, renderer, simulator);

  while (!window.ShouldClose()) {
    controller.control();
    simulator.simulate();
    renderer.render();  

    if(IsKeyPressed(KEY_ESCAPE)) EnableCursor();
  }

  return 0;
}

