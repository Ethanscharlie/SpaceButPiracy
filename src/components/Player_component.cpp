#include "Player_component.hpp"
#include "Event.hpp"
#include "InputManager.hpp"
#include "SDL_render.h"
#include "SolidBody.hpp"
#include "Vector2f.hpp"
#include "creaters/Bullet_creater.hpp"
#include "ldtk/LDTK_Tilemap.hpp"
#include "ldtkDefinition.hpp"

void Player::start() {
  Event::addEventListener("LeftMouseButtonDown", [this]() {
    Angle angle;
    angle.lookAt(entity->box.getCenter(),
                 InputManager::getMouseWorldPosition());
    createBullet(entity->box.getCenter(), angle.getVector() * 300);
  });

  Event::addEventListener("RoomFinish", [this]() {
    spawn = entity->box.position;
    finishedRooms.push_back(ldtk->currentLevel->iid);
  });

  spawn = entity->box.position;
}

void Player::update(float deltaTime) {
  std::vector<Box *> solids;
  for (LDTK::Tilemap *col : GameManager::getComponents<LDTK::Tilemap>()) {
    if (!col->layer)
      continue;
    if (!col->solid)
      continue;
    for (Box &box : col->layer->boxes) {
      solids.push_back(&box);
    }
  }
  for (SolidBody *col : GameManager::getComponents<SolidBody>()) {
    solids.push_back(&col->entity->box);
  }

  Vector2f move = InputManager::checkAxis() * deltaTime * 100;
  entity->box.slide(move, solids);

  if (move.x > 0) {
    entity->get<Sprite>()->image.flip = SDL_FLIP_NONE;
  } else if (move.x < 0) {
    entity->get<Sprite>()->image.flip = SDL_FLIP_HORIZONTAL;
  }

  for (Entity *bullet : GameManager::getEntities("EvilBullet")) {
    if (entity->box.checkCollision(bullet->box)) {
      bullet->toDestroy = true;
      health--;
    }
  }

  if (health <= 0) {
    health = 1;
    entity->box.position = spawn;
  }
}
