#include "EvilBullet_creater.hpp"
#include "components/Bullet_component.hpp"

Entity *createEvilbullet(Vector2f position, Vector2f force) {
  Entity *entity = GameManager::createEntity("EvilBullet");
  entity->box.setWithCenter(position);
  entity->box.size = {8, 8};
  entity->layer = 6;

  Sprite *sprite = entity->add<Sprite>();
  sprite->image = Image("res/images/bullet.png");
  Angle angle;
  angle.setWithVector(force);
  sprite->angle = angle;

  entity->add<Bullet>()->force = force;

  return entity;
}
