#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <vector>
#include <random>

#include "houseContainer.hpp"
#include "Player.hpp"

using namespace std;

class computerPlayer : public Player
{

public:
  computerPlayer();
  virtual houseContainer* chooseHouse();

private:
  std::minstd_rand generator;

};

#endif
