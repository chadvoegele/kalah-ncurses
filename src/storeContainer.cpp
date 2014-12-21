#include "storeContainer.hpp"

storeContainer::storeContainer()
{
  setSeedCount(0);
}

storeContainer::storeContainer(unsigned int initialSeedCount)
{
  setSeedCount(initialSeedCount);
}

storeContainer::storeContainer(const storeContainer& storeContainerOther)
{
  seedCount = storeContainerOther.getSeedCount();
  nextContainer = storeContainerOther.nextContainer;
}

storeContainer::~storeContainer()
{
}

bool storeContainer::isStore() const
{
  return true;
}

void storeContainer::assignContainerRefs(seedContainer* inNextContainer)
{
  nextContainer = inNextContainer;
}

bool storeContainer::kalahMoveSequence(unsigned int incomingSeeds,
                                       bool isOwnedByActivePlayer)
{
  if (incomingSeeds == 0)
    return false;

  if (isOwnedByActivePlayer)
  {
    int seedsLeft = takeOneSeed(incomingSeeds);

    if (seedsLeft == 0)
      return true;
    else
    {
      return nextContainer->kalahMoveSequence(seedsLeft, false);
    }
  }
  else
  {
    return nextContainer->kalahMoveSequence(incomingSeeds, true);
  }
}
