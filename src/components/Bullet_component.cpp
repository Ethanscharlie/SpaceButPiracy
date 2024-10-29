#include "Bullet_component.hpp"

void Bullet::start() {
}

void Bullet::update(float deltaTime) {
  entity->box.position += force * deltaTime;

  if (!entity->box.checkCollision(Camera::cameraLimitBox)) {
    entity->toDestroy = true;
  }
}
