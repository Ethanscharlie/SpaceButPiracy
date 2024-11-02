#include "Camera.hpp"
#include "Charlie2D.hpp"
#include "Math.hpp"
#include "components/Player_component.hpp"
#include "creaters/Player_creater.hpp"
#include "creaters/UpgradeMenu_mce.hpp"
#include "creaters/upgradeListing_mce.hpp"
#include "ldtkDefinition.hpp"
#include "ldtkLoader.hpp"
#include <iostream>

#include "config.h"

#define LEVEL_PIXEL_SIZE 352
#define SCALEUP_MULTIPLIER 5

int main(int, char **) {
  GameManager::init(
    Vector2f(LEVEL_PIXEL_SIZE, LEVEL_PIXEL_SIZE) * SCALEUP_MULTIPLIER
  );

  Camera::scale = SCALEUP_MULTIPLIER;

  Entity* player = createPlayer({0, 0});

  Entity* background = GameManager::createEntity("Background");
  background->renderPositionType = EntityRenderPositionType::Screen;
  background->box.size = GameManager::gameWindowSize;
  background->box.setWithCenter({0, 0});
  background->add<Sprite>()->image = Image("res/images/space.png");

  loadLdtk();
  ldtk->loadLevel("16eef591-73f0-11ef-a015-e1fef6b15dbf");

  player->box.setWithCenter(Camera::getPosition());
  player->get<Player>()->spawn = player->box.position;

  GameManager::doUpdateLoop();
  return 0;
}
