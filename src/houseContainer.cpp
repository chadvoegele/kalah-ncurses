#include "houseContainer.hpp"

houseContainer::houseContainer()
{
  setSeedCount(0);
}

houseContainer::houseContainer(unsigned int initialSeedCount)
{
  setSeedCount(initialSeedCount);
}

houseContainer::houseContainer(const houseContainer& houseContainerOther)
  : oppositeHouse(houseContainerOther.oppositeHouse),
  opponentStore(houseContainerOther.opponentStore),
  controlledStore(houseContainerOther.controlledStore)
{
  seedCount = houseContainerOther.getSeedCount();
  nextContainer = houseContainerOther.nextContainer;
}

houseContainer::~houseContainer()
{
}

bool houseContainer::isStore() const
{
  return false;
}

void houseContainer::assignContainerRefs(seedContainer* inNextContainer,
    houseContainer* inOppositeHouse, storeContainer* inOpponentStore,
    storeContainer* inControlledStore)
{
  nextContainer = inNextContainer;
  oppositeHouse = inOppositeHouse;
  opponentStore = inOpponentStore;
  controlledStore = inControlledStore;
}

void houseContainer::moveAllToOpponentStore()
{
  int seedCountToMove = getSeedCount();
  setSeedCount(0);
  opponentStore->setSeedCount(opponentStore->getSeedCount() + seedCountToMove);
}

void houseContainer::moveAllToControlledStore()
{
  int seedCountToMove = getSeedCount();
  setSeedCount(0);
  controlledStore->setSeedCount(controlledStore->getSeedCount() + seedCountToMove);
}

bool houseContainer::kalahMoveSequence(unsigned int incomingSeeds,
                                       bool isOwnedByActivePlayer)
{
  if (incomingSeeds == 0)
    return false;

  int seedsLeft = takeOneSeed(incomingSeeds);

  if (seedsLeft == 0 && getSeedCount() == 1 && isOwnedByActivePlayer)
  {
    oppositeHouse->moveAllToOpponentStore();
    moveAllToControlledStore();
    return false;
  }
  else
  {
    return nextContainer->kalahMoveSequence(seedsLeft, isOwnedByActivePlayer);
  }
}

bool houseContainer::initiateKalahMoveSequence()
{
  int seedsToMove = getSeedCount();
  setSeedCount(0);
  return nextContainer->kalahMoveSequence(seedsToMove, true);
}
