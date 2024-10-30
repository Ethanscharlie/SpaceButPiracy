#include "Soldier_creater.hpp"
#include "Vector2f.hpp"
#include "components/Soldier_component.hpp"

void createSoldier(Entity* entity) {
  Sprite *sprite = entity->add<Sprite>();
  sprite->image = Image("res/images/evilBean.png");

  entity->add<Soldier>();
}
