#pragma once
#include "model/world.h"
#include "model/simulator.h"
#include "view/renderer.h"

class Controller {
public:
  Renderer &renderer;
  Simulator &simulator;

  World &world;
  CelestialBody &target;
  
  float controlSpeed{0.01};

  raylib::Vector3 deltaV{0,0,0};

  Controller(World &w, Renderer &r, Simulator &s)
      : world(w), renderer(r), simulator(s), target(world.bodies[0]) {}

  void control();    
  void handleInput();
  void update();
};