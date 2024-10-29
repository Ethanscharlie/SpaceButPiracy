#include "ldtkLoader.hpp"

#include "ldtk/LDTK_Project.hpp"
#include "ldtkDefinition.hpp"

void loadLdtk() {
  ldtk = std::make_unique<LDTK::Project>("res/MetroidVaniaGame.ldtk");
  ldtk->render();
  ldtk->onLoadLevel = []() {
    Camera::cameraLimitBox = ldtk->currentLevel->levelBox;
    // GameManager::getEntities("Ground")[0]->get<LDTK::Tilemap>()->solid =
    // true;

    for (Entity *entity : ldtk->currentLevel->loadedEntites) {
    }
  };
}
