#ifndef STORE_CONTAINER_H
#define STORE_CONTAINER_H

#include "seedContainer.hpp"

class storeContainer : public seedContainer
{

public:
  storeContainer();
  storeContainer(unsigned int initialSeedCount);
  storeContainer(const storeContainer& storeContainerOther);
  virtual ~storeContainer();
  virtual bool isStore() const;
  void assignContainerRefs(seedContainer* nextContainer);
  virtual bool kalahMoveSequence(unsigned int incomingSeeds,
                                          bool isOwnedByActivePlayer);
};

#endif
