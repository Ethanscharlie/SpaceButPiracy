#include "components/RoomSwitcher.hpp"
#include "ldtk/LDTK_Level.hpp"
#include "ldtkDefinition.hpp"

void RoomSwitcher::start() {}

void RoomSwitcher::update(float deltaTime) {
  if (entity->box.getCenter().x >= ldtk->currentLevel->levelBox.getRight() ||
      entity->box.getCenter().x <= ldtk->currentLevel->levelBox.getLeft() ||
      entity->box.getCenter().y >= ldtk->currentLevel->levelBox.getBottom() ||
      entity->box.getCenter().y <= ldtk->currentLevel->levelBox.getTop()) {

    LDTK::Level *level = ldtk->findTraveledLevel(entity->box);
    ldtk->loadLevel(level->iid);
  }
}
