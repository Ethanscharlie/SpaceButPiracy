#pragma once

#include "Charlie2D.hpp"

class RoomSwitcher : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
};
