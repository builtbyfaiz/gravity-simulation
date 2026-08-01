#pragma once
#include "model/world.h"

class Renderer {
public:
  World &world;
  
  raylib::Camera3D camera{raylib::Vector3{0.0f, 15.0f, 15.0f},  // position
                          raylib::Vector3{0.0f, 0.0f, 0.0f},    // target
                          raylib::Vector3{0.0f, 1.0f, 0.0f},    // up
                          45.0f,                                // fovy
                          CAMERA_PERSPECTIVE};

  Renderer(World &w) : world(w) {};

  void render();
};