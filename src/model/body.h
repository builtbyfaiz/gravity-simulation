#pragma once
#include "raylib-cpp.hpp"

class CelestialBody {
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

    void move(raylib::Vector3 movementDelta);
    void rotate(raylib::Vector3 rotationDelta);

    void addMass(float mass);
    void addRadius(float radius);

    void setScale(float scale);

    // Constructor
    CelestialBody(
        float           m  = 1.0f,
        float           r  = 1.0f,
        Color           c  = RED,
        raylib::Vector3 p  = {0, 0, 0},
        raylib::Vector3 rt = {0, 0, 0},
        float           s  = 1.0f)
        
        : mass(m),
          color(c),
          scale(s),
          radius(r),
          position(p),
          rotation(rt),
          velocity((raylib::Vector3){0, 0, 0}),
          model(LoadModelFromMesh(GenMeshSphere(1.0f, 16, 16))){}
};