#pragma once

#include "Charlie2D.hpp"
#include "Vector2f.hpp"

class Bullet : public Component {
public:
  void start() override;
  void update(float deltaTime) override;

  Vector2f force;
};
