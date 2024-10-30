#include "Door_component.hpp"
#include "SolidBody.hpp"
#include "components/Soldier_component.hpp"

void Door::start() {
  entity->get<Sprite>()->setAlpha(0);
}

void Door::update(float deltaTime) {
  if (holdOpen) {
    if (!GameManager::getEntities("Player")[0]->box.checkCollision(
            entity->box)) {
      holdOpen = false;
      entity->add<SolidBody>();
      entity->get<Sprite>()->setAlpha(255);
    }
  } else {
    if (open) {

    } else {
      if (GameManager::getComponents<Soldier>().size() == 0) {
        entity->toDestroy = true;
      }
    }
  }
}
