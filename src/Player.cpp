#include "Player.hpp"

void Player::assignRefs(vector<houseContainer*> inControlledHouses, 
    const storeContainer* inControlledStore, Player* inOpponent)
{
  vector<houseContainer*> controlledHousesVector = vector<houseContainer*>(inControlledHouses);
  controlledHouses = controlledHousesVector;

  controlledStore = inControlledStore;

  opponent = inOpponent;
}

Player* Player::getOpponent()
{
  return opponent;
}

const storeContainer* Player::getStore() const
{
  return controlledStore;
}

string Player::getName() const
{
  return name;
}
