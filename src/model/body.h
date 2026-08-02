#pragma once
#include "raylib-cpp.hpp"

class CelestialBody
{
  public:
    // Render
    Model model;
    Color color;

    // Transform
    raylib::Vector3 rotation;
    float scale;

    // Physics
    float mass;
    float radius;
    raylib::Vector3 position;
    raylib::Vector3 velocity;
    raylib::Vector3 acceleration;

    void move(raylib::Vector3 movementDelta);
    void rotate(raylib::Vector3 rotationDelta);

    void addMass(float mass);
    void addRadius(float radius);
    void addVelocity(raylib::Vector3 velocity);
    void addAcceleration(raylib::Vector3 acceleration);

    void setScale(float scale);

    // Constructor
    CelestialBody(float mass = 1.0f,
                  float           radius   = 1.0f,
                  Color           color    = RED,
                  raylib::Vector3 position = {0, 0, 0},
                  raylib::Vector3 rotation = {0, 0, 0},
                  raylib::Vector3 velocity = {0, 0, 0},
                  float           scale    = 1.0f)

        : mass(mass), 
          color(color), 
          scale(scale), 
          radius(radius), 
          position(position),
          rotation(rotation), 
          velocity(velocity),
          model(LoadModelFromMesh(GenMeshSphere(1.0f, 16, 16))) {}
};