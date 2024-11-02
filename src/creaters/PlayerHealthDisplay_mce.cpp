#include "PlayerHealthDisplay_mce.hpp"
#include "Math.hpp"
#include "components/Player_component.hpp"
#include <format>
#include <string>

#define ENTITY_TAG "{}"
#define IMAGE_FILE ""
#define SIZE {1000, 1000}

void PlayerHealthDisplay::start() {}

void PlayerHealthDisplay::update(float deltaTime) {
  int health = GameManager::getComponents<Player>()[0]->health;
  int maxHealth = GameManager::getComponents<Player>()[0]->maxHealth;
  int damage = GameManager::getComponents<Player>()[0]->damage;
  float speed = GameManager::getComponents<Player>()[0]->speed;

  entity->get<Text>()->text =
      std::format("Health: {}/{}\nDamage: {}\nSpeed: {}", health, maxHealth,
                  damage, floatToString(speed));
}

void PlayerHealthDisplay::createInstance(Vector2f centerPosition) {
  Entity *entity = GameManager::createEntity(ENTITY_TAG);
  entity->box.size = SIZE;
  entity->renderPositionType = EntityRenderPositionType::Screen;
  entity->layer = 60;
  entity->box.setWithCenter(centerPosition);
  configureInstance(entity);
}

void PlayerHealthDisplay::configureInstance(Entity *entity) {
  if ((std::string)IMAGE_FILE != "") {
    Sprite *sprite = entity->add<Sprite>();
    sprite->image = {IMAGE_FILE};
  }

  Text *textComponent = entity->add<Text>();
  textComponent->changeFont("res/fonts/prstart.ttf", 50);
  textComponent->text_color = {255, 255, 255};
  textComponent->text = std::format("Health: {}", 2);

  entity->add<PlayerHealthDisplay>();
}
