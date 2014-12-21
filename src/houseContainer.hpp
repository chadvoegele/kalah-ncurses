#ifndef HOUSE_CONTAINER_H
#define HOUSE_CONTAINER_H

#include "seedContainer.hpp"
#include "storeContainer.hpp"

class houseContainer : public seedContainer
{

public:
  houseContainer();
  houseContainer(unsigned int initialSeedCount);
  houseContainer(const houseContainer& houseContainerOther);
  virtual ~houseContainer();
  virtual bool isStore() const;
  void assignContainerRefs(seedContainer* nextContainer,
                           houseContainer* oppositeHouse, 
                           storeContainer* opponentStore,
                           storeContainer* controlledStore);
  virtual void moveAllToOpponentStore();
  virtual void moveAllToControlledStore();
  virtual bool kalahMoveSequence(unsigned int incomingSeeds,
                                 bool isOwnedByActivePlayer);
  bool initiateKalahMoveSequence();

private:
  houseContainer* oppositeHouse;
  storeContainer* opponentStore;
  storeContainer* controlledStore;

};

#endif
