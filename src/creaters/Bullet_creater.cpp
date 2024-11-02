#include "Bullet_creater.hpp"
#include "Vector2f.hpp"
#include "components/Bullet_component.hpp"

Entity* createBullet(Vector2f position, Vector2f force, int damage) {
    Entity* entity = GameManager::createEntity("Bullet");
    entity->box.setWithCenter(position);
    entity->box.size = {8, 8};
    entity->layer = 6;

    Sprite* sprite = entity->add<Sprite>();
    sprite->image = Image("res/images/bullet.png");
    Angle angle;
    angle.setWithVector(force);
    sprite->angle = angle;

    entity->add<Bullet>()->force = force;
    entity->get<Bullet>()->damage = damage;
    
    return entity;
}
