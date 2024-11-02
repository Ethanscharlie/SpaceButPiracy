#include "upgradeListing_mce.hpp"
#include "Math.hpp"
#include "components/Player_component.hpp"
#include "creaters/UpgradeMenu_mce.hpp"
#include <format>

#define ENTITY_TAG "upgrade listing"
#define SIZE {600, 200}

void upgradeListing::start() {
  entity->add<Scheduler>()->addSchedule(
      "cooldown", 1000, [this]() { cooldown = true; }, true);
}

void upgradeListing::update(float deltaTime) {
  entity->get<Sprite>()->update(deltaTime);
  entity->get<Text>()->update(deltaTime);

  if (!cooldown)
    return;

  touching = false;
  Vector2f mousePos;
  if (checkInWorld) {
    mousePos = InputManager::getMouseWorldPosition();
  } else {
    mousePos = InputManager::getMouseUIPosition();
  }

  touching = entity->box.getLeft() < mousePos.x &&
             entity->box.getRight() > mousePos.x &&
             entity->box.getTop() < mousePos.y &&
             entity->box.getBottom() > mousePos.y;

  if (touching) {
    onHover();
    if (InputManager::mouseHeld) {
      onHold();
    }
  } else {
    offHover();
  }
}

Entity *upgradeListing::createInstance(Vector2f centerPosition,
                                       std::string upgrade) {
  Entity *entity = GameManager::createEntity(ENTITY_TAG);
  entity->renderPositionType = EntityRenderPositionType::Screen;
  entity->layer = 60;
  entity->box.size = SIZE;
  entity->box.setWithCenter(centerPosition);
  configureInstance(entity, upgrade);
  return entity;
}

void upgradeListing::configureInstance(Entity *entity, std::string upgrade) {
  entity->add<Sprite>()->image = Image("res/images/navy.png");
  entity->get<Sprite>()->standardUpdate = false;

  Text *textComponent = entity->add<Text>();
  textComponent->changeFont("res/fonts/prstart.ttf", 30);
  textComponent->text_color = {255, 255, 255};
  textComponent->standardUpdate = false;
  textComponent->text = upgrade;

  upgradeListing *button = entity->add<upgradeListing>();
  button->offHover = [textComponent, upgrade]() {
    textComponent->text = upgrade;
  };
  button->onHover = [textComponent, upgrade]() {
    textComponent->text = std::format("-- {} --", upgrade);
    if (InputManager::mouseHeld) {

      Player *player = GameManager::getComponents<Player>()[0];

      if (upgrade == "Health") {
        player->maxHealth++;
        player->health = player->maxHealth;
      } else if (upgrade == "Damage") {
        player->damage++;
      }

      GameManager::getComponents<UpgradeMenu>()[0]->entity->toDestroy = true;
    }
  };
}
