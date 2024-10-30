#include "ldtkLoader.hpp"

#include "Event.hpp"
#include "components/Player_component.hpp"
#include "creaters/Door_creater.hpp"
#include "creaters/Soldier_creater.hpp"
#include "ldtk/LDTK_Project.hpp"
#include "ldtk/LDTK_Tilemap.hpp"
#include "ldtkDefinition.hpp"
#include <algorithm>
#include <vector>

void loadLdtk() {
  ldtk = std::make_unique<LDTK::Project>("res/SpacePirateGame.ldtk");
  ldtk->render();
  ldtk->onLoadLevel = []() {
    Event::fireEvent("LDTKLevelChange");
    Camera::cameraLimitBox = ldtk->currentLevel->levelBox;
    Camera::setPosition(ldtk->currentLevel->levelBox.getCenter());
    GameManager::getEntities("Ground")[0]->get<LDTK::Tilemap>()->solid = true;

    std::vector<std::string> &finishedRooms =
        GameManager::getEntities("Player")[0]->get<Player>()->finishedRooms;
    bool isFinished = std::find(finishedRooms.begin(), finishedRooms.end(),
                                ldtk->currentLevel->iid) != finishedRooms.end();

    for (Entity *entity : ldtk->currentLevel->loadedEntites) {
      if (!isFinished) {
        if (entity->tag == "Soldier") {
          createSoldier(entity);
        }
      }

      if (entity->tag == "DoorH") {
        createDoor(entity, true);
      }

      else if (entity->tag == "DoorV") {
        createDoor(entity, false);
      }
    }
  };
}
