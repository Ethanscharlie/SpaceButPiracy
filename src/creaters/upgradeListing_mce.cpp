#include "upgradeListing_mce.hpp"
#include "Math.hpp"

#define ENTITY_TAG "upgrade listing"
#define SIZE {600, 200}

void upgradeListing::start() {}

void upgradeListing::update(float deltaTime) {
  entity->get<Sprite>()->update(deltaTime);
  entity->get<Text>()->update(deltaTime);
}

Entity *upgradeListing::createInstance(Vector2f centerPosition) {
  Entity *entity = GameManager::createEntity(ENTITY_TAG);
  entity->renderPositionType = EntityRenderPositionType::Screen;
  entity->layer = 60;
  entity->box.size = SIZE;
  entity->box.setWithCenter(centerPosition);
  configureInstance(entity);
  return entity;
}

void upgradeListing::configureInstance(Entity *entity) {
  entity->add<Sprite>()->image = Image("res/images/navy.png");
  entity->get<Sprite>()->standardUpdate = false;

  Text *textComponent = entity->add<Text>();
  textComponent->changeFont("res/fonts/prstart.ttf", 30);
  textComponent->text_color = {255, 255, 255};
  textComponent->text = "Health +";
  textComponent->standardUpdate = false;

  Button* button = entity->add<Button>();
  button->onHover = [textComponent]() {
    textComponent->text = "-- Health + --";
  };
  button->offHover = [textComponent]() {
    textComponent->text = "Health +";
  };
  button->onClick = []() {
    Event::fireEvent("CloseUpgradeMenu");
  };

  entity->add<upgradeListing>();
}
