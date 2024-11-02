#pragma once

#include "Charlie2D.hpp"

class UpgradeMenu : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
  void onDestroy() override;
  static Entity *createInstance(Vector2f centerPosition = {0, -400});
  static void configureInstance(Entity *entity);

private:
  Entity *upgrade1;
  Entity *upgrade2;
  Entity *upgrade3;
};
