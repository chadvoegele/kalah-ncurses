#include "computerPlayer.hpp"
#include <ctime>


computerPlayer::computerPlayer()
{
  name = "Computer";
  std::minstd_rand generator((unsigned int)time(NULL));
}

houseContainer* computerPlayer::chooseHouse()
{
  std::uniform_int_distribution<> dist(0, controlledHouses.size()-1);
  int chosenHouseIndex = dist(generator);
  return controlledHouses[chosenHouseIndex];
}
