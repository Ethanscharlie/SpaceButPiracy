#include "ldtkLoader.hpp"

#include "creaters/Soldier_creater.hpp"
#include "ldtk/LDTK_Project.hpp"
#include "ldtk/LDTK_Tilemap.hpp"
#include "ldtkDefinition.hpp"

void loadLdtk() {
  ldtk = std::make_unique<LDTK::Project>("res/SpacePirateGame.ldtk");
  ldtk->render();
  ldtk->onLoadLevel = []() {
    Camera::cameraLimitBox = ldtk->currentLevel->levelBox;
    Camera::setPosition(ldtk->currentLevel->levelBox.getCenter());
    GameManager::getEntities("Ground")[0]->get<LDTK::Tilemap>()->solid = true;

    for (Entity *entity : ldtk->currentLevel->loadedEntites) {
      if (entity->tag == "Soldier") {
        createSoldier(entity);
      }
    }
  };
}
