#include "controller.h"

void Controller::handleInput()
{

    deltaV = (Vector3){0, 0, 0};

    if (!world.camMode)
    {
        if (IsKeyPressed(KEY_LEFT_SHIFT)) controlSpeed *= 2.0;
        if (IsKeyPressed(KEY_SPACE))      controlSpeed /= 2.0;

        if (IsKeyDown(KEY_W)) deltaV.SetZ(-controlSpeed);
        if (IsKeyDown(KEY_S)) deltaV.SetZ(controlSpeed);

        if (IsKeyDown(KEY_A)) deltaV.SetX(-controlSpeed);
        if (IsKeyDown(KEY_D)) deltaV.SetX(controlSpeed);

        if (IsKeyDown(KEY_E)) deltaV.SetY(controlSpeed);
        if (IsKeyDown(KEY_Q)) deltaV.SetY(-controlSpeed);

        if (IsKeyPressed(KEY_T)) world.changeTarget();
    }

    world.getSelected().addVelocity(deltaV);

    if (IsKeyPressed(KEY_C)) world.toggleCamMode();
}

void Controller::update() {}

void Controller::control()
{
    handleInput();
    update();
}