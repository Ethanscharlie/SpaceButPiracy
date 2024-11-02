#include "UpgradeMenu_mce.hpp"
#include "creaters/upgradeListing_mce.hpp"

#define ENTITY_TAG "{}"
#define IMAGE_FILE ""
#define SIZE {600, 200}

void UpgradeMenu::start() {}

void UpgradeMenu::update(float deltaTime) {}

Entity *UpgradeMenu::createInstance(Vector2f centerPosition) {
  if (GameManager::getComponents<UpgradeMenu>().size() > 0) {
    return nullptr;
  }

  Entity *entity = GameManager::createEntity(ENTITY_TAG);
  entity->renderPositionType = EntityRenderPositionType::Screen;
  entity->layer = 60;
  entity->box.size = SIZE;
  entity->box.setWithCenter(centerPosition);
  configureInstance(entity);
  return entity;
}

void UpgradeMenu::configureInstance(Entity *entity) {
  if ((std::string)IMAGE_FILE != "") {
    Sprite *sprite = entity->add<Sprite>();
    sprite->image = {IMAGE_FILE};
  }

  Text *textComponent = entity->add<Text>();
  textComponent->changeFont("res/fonts/prstart.ttf", 30);
  textComponent->text_color = {255, 255, 255};
  textComponent->text = "Select an upgrade";

  UpgradeMenu *upgradeMenu = entity->add<UpgradeMenu>();
  upgradeMenu->upgrade1 = upgradeListing::createInstance({0, -200}, "Health");
  upgradeMenu->upgrade2 = upgradeListing::createInstance({0, 100}, "Damage");
  upgradeMenu->upgrade3 = upgradeListing::createInstance({0, 400}, "Health");
}

void UpgradeMenu::onDestroy() {
  upgrade1->toDestroy = true;
  upgrade2->toDestroy = true;
  upgrade3->toDestroy = true;
}
