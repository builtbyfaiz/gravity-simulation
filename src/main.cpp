#include "raylib-cpp.hpp"

int main() {
  raylib::Window window(1280, 800, "");
  SetTargetFPS(60);

  raylib::Camera3D camera{raylib::Vector3{10.0f, 10.0f, 10.0f}, // position
                          raylib::Vector3{0.0f, 0.0f, 0.0f},    // target
                          raylib::Vector3{0.0f, 1.0f, 0.0f},    // up
                          45.0f,                                // fovy
                          CAMERA_PERSPECTIVE};

  while (!window.ShouldClose()) {
    camera.Update(CAMERA_FREE);

    BeginDrawing();
    window.ClearBackground(RAYWHITE);
    DrawFPS(10, 10);

    camera.BeginMode();
    DrawGrid(20, 1.0f);
    camera.EndMode();

    EndDrawing();
  }
  return 0;
}