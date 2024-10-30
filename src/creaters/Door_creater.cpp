#include "Door_creater.hpp"
#include "SolidBody.hpp"
#include "components/Door_component.hpp"

void createDoor(Entity *entity, bool isHorizontal) {
  Sprite *sprite = entity->add<Sprite>();

  if (isHorizontal) {
    sprite->image = Image("res/images/doorH.png");
  } else {
    sprite->image = Image("res/images/doorV.png");
  }
  
  entity->add<Door>();
}
