#include "Soldier_component.hpp"
#include "Scheduler.hpp"
#include "Vector2f.hpp"
#include "components/Bullet_component.hpp"
#include "creaters/EvilBullet_creater.hpp"

void Soldier::start() {
  entity->add<Scheduler>()->addSchedule("Fire", 1000, [this]() {
    Angle angle;
    angle.lookAt(entity->box.getCenter(),
                 GameManager::getEntities("Player")[0]->box.getCenter());
    createEvilbullet(entity->box.getCenter(), angle.getVector() * 100);
  });
}

void Soldier::update(float deltaTime) {
  Entity *target = GameManager::getEntities("Player")[0];
  Angle angle;
  angle.lookAt(entity->box.getCenter(), target->box.getCenter());

  Vector2f move = angle.getVector() * deltaTime * 50;
  entity->box.position += move;

  if (move.x > 0) {
    entity->get<Sprite>()->image.flip = SDL_FLIP_NONE;
  } else if (move.x < 0) {
    entity->get<Sprite>()->image.flip = SDL_FLIP_HORIZONTAL;
  }

  for (Entity *bullet : GameManager::getEntities("Bullet")) {
    if (entity->box.checkCollision(bullet->box)) {
      bullet->toDestroy = true;
      health--;
    }
  }

  if (health <= 0) {
    entity->toDestroy = true;
  }
}
