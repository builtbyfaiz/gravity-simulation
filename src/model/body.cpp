#include "body.h"

// Moves the body by 3D vector
void CelestialBody::move(raylib::Vector3 movementDelta) { position += movementDelta; };

// Rotates the body by 3D vector
void CelestialBody::rotate(raylib::Vector3 rotationDelta) { rotation += rotationDelta; };

// Adds or Subtracts given mass from body's mass
void CelestialBody::addMass(float massDelta) { mass += massDelta; };

// Increases or Decreases radius from Body's radius
void CelestialBody::addRadius(float radiusDelta) { radius += radiusDelta; }

// Increases or Decreases velocity from Body's velocity
void CelestialBody::addVelocity(raylib::Vector3 velocityDelta) { velocity += velocityDelta; }

void CelestialBody::addAcceleration(raylib::Vector3 accelerationDelta)
{
    acceleration += accelerationDelta;
}

// Sets body's visual scale, This does not affect physics.
void CelestialBody::setScale(float s) { this->scale = s; };