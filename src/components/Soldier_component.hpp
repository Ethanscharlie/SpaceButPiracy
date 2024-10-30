#pragma once

#include "Charlie2D.hpp"

class Soldier : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
  int health = 10;
};
