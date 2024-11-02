#pragma once

#include "Charlie2D.hpp"

class upgradeListing : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
  static Entity* createInstance(Vector2f centerPosition, std::string upgrade);
  static void configureInstance(Entity* entity, std::string upgrade);

  std::function<void()> onClick = []() {};
  std::function<void()> onHold = []() {};
  std::function<void()> onHover = []() {};
  std::function<void()> offHover = []() {};

  bool checkInWorld = false;
  bool touching = false;
};

