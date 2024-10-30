#pragma once

#include "Charlie2D.hpp"

class Door : public Component {
public:
  void start() override;
  void update(float deltaTime) override;

  bool holdOpen = true;
  bool open = false;
};
