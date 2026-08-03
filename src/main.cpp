#include "raylib-cpp.hpp"
#include "view/renderer.h"
#include "model/simulator.h"
#include "controller/controller.h"

int main() {
  raylib::Window window(1280, 800, "");
  SetTargetFPS(60);
  DisableCursor();

  // SI accurate units
  CelestialBody earth, moon;
  earth.mass   = 5.97219e24;
  earth.radius = 6.371e6;

  moon.mass    = 7.34767309e22;
  moon.radius  = 1.7374e6;

  moon.move({384400000, 0, 0}); 
  moon.addVelocity({0, 1022, 0});

  earth.model = LoadModelFromMesh(GenMeshSphere(1.0f, 16, 16));
  moon.model  = LoadModelFromMesh(GenMeshSphere(1.0f, 16, 16));
  
  World world;
  world.addBody(earth);
  world.addBody(moon);

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
