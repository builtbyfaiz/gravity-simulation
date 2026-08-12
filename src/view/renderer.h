#pragma once
#include "model/world.h"

class Renderer {
public:
  World &world;

  raylib::Vector3 renderPosition{0,0,0}, renderRadius{0,0,0}; // Planet attributes on render scale
  
  raylib::Camera3D camera{raylib::Vector3{0.0f, 15.0f, 15.0f},  // position
                          raylib::Vector3{0.0f, 0.0f, 0.0f},    // target
                          raylib::Vector3{0.0f, 1.0f, 0.0f},    // up
                          45.0f,                                // fovy
                          CAMERA_PERSPECTIVE};

  Renderer(World &w) : world(w) {};
  Font mono = LoadFontEx("C:/Windows/Fonts/consola.ttf", 20, 0, 0);

  void render();

  std::string toString(const raylib::Vector3 &vector3); // Vector3 to String
};