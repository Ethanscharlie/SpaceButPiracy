#include "Camera.hpp"
#include "Charlie2D.hpp"
#include "creaters/Player_creater.hpp"
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

  loadLdtk();
  ldtk->loadLevel("16eef591-73f0-11ef-a015-e1fef6b15dbf");

  player->box.setWithCenter(Camera::getPosition());

  GameManager::doUpdateLoop();
  return 0;
}
