#include "world.h"

#include <iostream>

void World::toggleCamMode()
{
    camMode = camMode ? false : true;
    std::cout << camMode;
}

// Adds a celestial body to the world
void World::addBody(CelestialBody body)
{
    bodies.push_back(body);
    selectedIndex++;
}

CelestialBody &World::getSelected() { return bodies[selectedIndex]; }

World::World()
{
    // SI accurate units, epoch 2026-08-27, remapped to Y-up (for raylib)
    CelestialBody sun, mercury, venus, earth, moon, mars, jupiter, saturn, uranus, neptune;
    
    sun.mass   = 1.98892e30;
    sun.radius = 6.9634e8;
    sun.color  = YELLOW;
    sun.move({0, 0, 0});
    sun.addVelocity({0, 0, 0});

    mercury.mass   = 3.3011e23;
    mercury.radius = 2.4397e6;
    mercury.color  = GRAY;
    mercury.move({-48049537434.63f, 6196275995.06f, 21894955820.09f});
    mercury.addVelocity({-30229.73f, -681.58f, -42265.98f});

    venus.mass   = 4.8675e24;
    venus.radius = 6.0518e6;
    venus.color  = ORANGE;
    venus.move({53812110447.61f, -4404646396.28f, -94603265432.65f});
    venus.addVelocity({30205.07f, -1506.55f, 17195.38f});

    earth.mass   = 5.97219e24;
    earth.radius = 6.371e6;
    earth.color  = GREEN;
    earth.move({136241487368.13f, 3094497.09f, -65397345644.25f});
    earth.addVelocity({12402.53f, -2.81f, 26732.42f});

      // Moon: Earth-relative vector added onto Earth's absolute vector
    moon.mass   = 7.34767309e22;
    moon.radius = 1.7374e6;
    moon.color  = LIGHTGRAY;
    moon.move({earth.position.x + 346003849.34f, 
               earth.position.y + 1749859.72f  ,
               earth.position.z + -182209430.94f});

    moon.addVelocity({earth.velocity.x + 430.84f,
                      earth.velocity.y + 92.53f ,
                      earth.velocity.z + 909.29f});

    mars.mass   = 6.4171e23;
    mars.radius = 3.3895e6;
    mars.color  = RED;
    mars.move({85333698669.91f, 2306455983.77f, 209906018614.77f});
    mars.addVelocity({-21526.29f, 762.25f, 11185.86f});

    jupiter.mass   = 1.8982e27;
    jupiter.radius = 6.9911e7;
    jupiter.color  = BEIGE;
    jupiter.move({-492194063713.56f, 8433626665.65f, 620736895796.18f});
    jupiter.addVelocity({-10397.79f, 263.88f, -7514.86f});

    saturn.mass   = 5.6834e26;
    saturn.radius = 5.8232e7;
    saturn.color  = GOLD;
    saturn.move({1391759829550.52f, -59518266352.66f, 236441384567.66f});
    saturn.addVelocity({-2154.68f, -79.10f, 9497.90f});

    uranus.mass   = 8.6810e25;
    uranus.radius = 2.5362e7;
    uranus.color  = SKYBLUE;
    uranus.move({1353934763065.80f, -7991994102.06f, 2575029963079.39f});
    uranus.addVelocity({-6088.44f, 89.27f, 2848.27f});

    neptune.mass   = 1.02413e26;
    neptune.radius = 2.4622e7;
    neptune.color  = BLUE;
    neptune.move({4464479393161.96f, -106803820158.95f, 190434372814.00f});
    neptune.addVelocity({-276.38f, -106.38f, 5459.12f});

    // models
    for (auto *body : {&sun, &mercury, &venus, &earth, &moon, &mars, &jupiter, &saturn, &uranus, &neptune})
        body->model = LoadModelFromMesh(GenMeshSphere(1.0f, 16, 16));

    for (auto *body : {&sun, &mercury, &venus, &earth, &moon, &mars, &jupiter, &saturn, &uranus, &neptune})
         addBody(*body);
}

void World::changeTarget()
{
    selectedIndex++;
    selectedIndex = selectedIndex % bodies.size();
}