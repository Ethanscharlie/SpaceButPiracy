#include "Player_creater.hpp"
#include "components/Player_component.hpp"

Entity *createPlayer(Vector2f position) {
  Entity *entity = GameManager::createEntity("Player");
  entity->box.size = {16, 16};
  entity->box.setWithCenter(position);
  entity->layer = 5;

  Sprite *sprite = entity->add<Sprite>();
  sprite->image = Image("res/images/spaceBean.png");

  entity->add<Player>();

  return entity;
}
