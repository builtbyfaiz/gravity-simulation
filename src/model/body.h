#pragma once
#include "raylib-cpp.hpp"

class Body {
public:
  // Mesh
  raylib::Model model = LoadModelFromMesh(GenMeshSphere(2.0f, 16, 16));

  // Transform
  raylib::Vector3 position;
  raylib::Vector3 rotation;
  raylib::Vector3 scale;

  // Physics
  float mass;
  float radius;

  void move(raylib::Vector3 movementDelta);
  void rotate(raylib::Vector3 rotationDelta);

  void addMass(float mass);
  void addRadius(float radius);

  void setScale(raylib::Vector3 scale);
};