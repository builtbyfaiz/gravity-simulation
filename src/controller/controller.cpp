#include "controller.h"

void Controller::handleInput()
{
    deltaV = (Vector3){0, 0, 0};

    if (!world.camMode)
    {
        if (IsKeyPressed(KEY_R)) speedLevel++;
        if (IsKeyPressed(KEY_F)) speedLevel--;

        if (IsKeyDown(KEY_W)) deltaV.SetZ(-controlStep);
        if (IsKeyDown(KEY_S)) deltaV.SetZ(controlStep);

        if (IsKeyDown(KEY_A)) deltaV.SetX(-controlStep);
        if (IsKeyDown(KEY_D)) deltaV.SetX(controlStep);

        if (IsKeyDown(KEY_E)) deltaV.SetY(controlStep);
        if (IsKeyDown(KEY_Q)) deltaV.SetY(-controlStep);

        if (IsKeyPressed(KEY_T)) world.changeTarget();
    }
    
    controlStep  = 1.0;                     // First, set control speed to a base speed.
    controlStep *= powf(2.0f, speedLevel);  // Exponential speed growth

    // Temporary modifiers
    if (IsKeyDown(KEY_LEFT_SHIFT))
        controlStep *= 10.0f;

    if (IsKeyDown(KEY_LEFT_CONTROL))
        controlStep *= 0.1f;

    world.getSelected().addVelocity(deltaV);

    if (IsKeyPressed(KEY_C)) world.toggleCamMode();
    
    if (IsKeyPressed(KEY_U)) world.planetScale++;
    if (IsKeyPressed(KEY_J)) world.planetScale--;
    if (IsKeyPressed(KEY_I)) world.renderScale *= controlStep;
    if (IsKeyPressed(KEY_K)) world.renderScale /= controlStep;
    if (IsKeyPressed(KEY_O)) world.simulationScale *= controlStep;
    if (IsKeyPressed(KEY_L)) world.simulationScale /= controlStep;
}

void Controller::update() {}

void Controller::control()
{
    handleInput();
    update();
}