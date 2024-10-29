#pragma once

#include "Charlie2D.hpp"
#include "Vector2f.hpp"

class Player : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
};
