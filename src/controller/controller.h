#pragma once
#include "model/simulator.h"
#include "model/world.h"
#include "view/renderer.h"


class Controller
{
  public:
    Renderer &renderer;
    Simulator &simulator;

    World &world;

    float controlSpeed{0.01};

    raylib::Vector3 deltaV{0, 0, 0};

    Controller(World &w, Renderer &r, Simulator &s) : world(w), renderer(r), simulator(s) {}

    void control();
    void handleInput();
    void update();
};