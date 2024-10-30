#pragma once

#include "Charlie2D.hpp"
#include "Vector2f.hpp"

class Player : public Component {
public:
  void start() override;
  void update(float deltaTime) override;

  Vector2f spawn;
  int health = 1;
  std::vector<std::string> finishedRooms;
};
