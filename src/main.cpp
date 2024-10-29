#include "Camera.hpp"
#include "Charlie2D.hpp"
#include "ldtkDefinition.hpp"
#include "ldtkLoader.hpp"
#include <iostream>

#include "config.h"

/*
 * Some useful code snips
 *
 * LDTK::loadJson("res/ldtk.ldtk");
 * LDTK::onLoadLevel = [](auto entities) {
 *   for (Entity *entity : entities) {
 *     if (entity->tag == "Player")
 *      std::cout << "Player\n";
 *   }
 * };
 * LDTK::loadLevel("65ba8250-25d0-11ef-b0ef-03acbc99fa7b");
*/

#define LEVEL_PIXEL_SIZE 352
#define SCALEUP_MULTIPLIER 5

int main(int, char **) {
  GameManager::init(
    Vector2f(LEVEL_PIXEL_SIZE, LEVEL_PIXEL_SIZE) * SCALEUP_MULTIPLIER
  );

  Camera::scale = SCALEUP_MULTIPLIER;

  loadLdtk();
  ldtk->loadLevel("16eef591-73f0-11ef-a015-e1fef6b15dbf");

  GameManager::doUpdateLoop();
  return 0;
}
