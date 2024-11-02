#include "Door_component.hpp"
#include "SolidBody.hpp"
#include "components/Player_component.hpp"
#include "components/Soldier_component.hpp"
#include "creaters/UpgradeMenu_mce.hpp"
#include "ldtkDefinition.hpp"

void Door::start() { entity->get<Sprite>()->setAlpha(0); }

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

        auto &finishedRooms =
            GameManager::getComponents<Player>()[0]->finishedRooms;
        if (std::find(finishedRooms.begin(), finishedRooms.end(),
                      ldtk->currentLevel->iid) == finishedRooms.end()) {
          Event::fireEvent("RoomFinish");
          UpgradeMenu::createInstance();
        }
      }
    }
  }
}
