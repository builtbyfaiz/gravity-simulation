#pragma once
#include "raylib-cpp.hpp"

class CelestialBody
{
  public:
    // Render
    Model model;
    Color color;

    // Transform, #TODO, make it into proper Rotational Axis and speed
    raylib::Vector3 rotation;

    // Physics
    float mass;
    float radius;
    raylib::Vector3 position;
    raylib::Vector3 velocity;
    raylib::Vector3 acceleration;

    void move(raylib::Vector3 movementDelta);
    void rotate(raylib::Vector3 rotationDelta);

    void addMass(double mass);
    void addRadius(double radius);

    void addVelocity(raylib::Vector3 velocity);
    void addAcceleration(raylib::Vector3 acceleration);

    // Constructor
    CelestialBody(double          mass     = 1.0f,
                  double          radius   = 1.0f,
                  Color           color    = RED,
                  raylib::Vector3 position = {0, 0, 0},
                  raylib::Vector3 rotation = {0, 0, 0},
                  raylib::Vector3 velocity = {0, 0, 0})

        : mass(mass), 
          color(color), 
          radius(radius), 
          position(position),
          rotation(rotation), 
          velocity(velocity),
          model(LoadModelFromMesh(GenMeshSphere(1.0f, 16, 16))) {}
};