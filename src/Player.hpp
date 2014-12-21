#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "houseContainer.hpp"

using namespace std;

class Player
{

public:
  virtual houseContainer* chooseHouse() = 0;
  virtual void assignRefs(vector<houseContainer*> inControlledHouses, 
      const storeContainer* inControlledStore, Player* inOpponent);
  virtual Player* getOpponent();
  virtual const storeContainer* getStore() const;
  virtual string getName() const;

protected:
  vector<houseContainer*> controlledHouses;
  const storeContainer* controlledStore;
  Player* opponent;
  string name;

};

#endif
