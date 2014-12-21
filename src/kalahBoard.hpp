#ifndef KALAH_BOARD_H
#define KALAH_BOARD_H

#include <vector>

#include "houseContainer.hpp"
#include "storeContainer.hpp"

using namespace std;

class kalahBoard
{

public:
  kalahBoard(unsigned int numberOfHousesIn);
  void fillHouses(vector<unsigned int> homeHouseInitialSeedCount,
      vector<unsigned int> awayHouseInitialSeedCount);
  unsigned int getNumberOfHouses();
  vector<houseContainer> homeHouses;
  vector<houseContainer> awayHouses;
  storeContainer homeStore;
  storeContainer awayStore;

private:
  void assignContainerRefs();
  unsigned int numberOfHouses;

};

#endif
