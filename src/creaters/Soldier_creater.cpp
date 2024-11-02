#include "Soldier_creater.hpp"
#include "Vector2f.hpp"
#include "components/Soldier_component.hpp"
#include "ldtk/LDTK_EntityData.hpp"
#include <any>

void createSoldier(Entity *entity) {
  Sprite *sprite = entity->add<Sprite>();
  sprite->image = Image("res/images/evilBean.png");

  int health = std::any_cast<int>(entity->get<LDTK::EntityData>()
                                      ->instance->fieldInstances.at("Health")
                                      .getValue());
  entity->add<Soldier>()->health = health;
}
