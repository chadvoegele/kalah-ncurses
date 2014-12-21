#include <stdexcept>

#include "kalahBoard.hpp"

using namespace std;

kalahBoard::kalahBoard(unsigned int numberOfHousesIn) 
  : homeHouses(numberOfHousesIn, houseContainer()), awayHouses(numberOfHousesIn, houseContainer())
{
  if (!(numberOfHousesIn > 2))
    throw domain_error("number of house must be greater than 2");

  numberOfHouses = numberOfHousesIn;

  assignContainerRefs();
}

void kalahBoard::assignContainerRefs()
{
  for (unsigned int i = 1; i < numberOfHouses - 1; i++)
  {
    homeHouses[i].assignContainerRefs(&homeHouses[i+1], &awayHouses[i], &awayStore, &homeStore);
    awayHouses[i].assignContainerRefs(&awayHouses[i-1], &homeHouses[i], &homeStore, &awayStore);
  }

  awayStore.assignContainerRefs(&homeHouses[0]);
  homeStore.assignContainerRefs(&awayHouses[numberOfHouses-1]);

  homeHouses[0].assignContainerRefs(&homeHouses[1], &awayHouses[0], &awayStore, &homeStore);
  homeHouses[numberOfHouses-1].assignContainerRefs(&homeStore,
      &awayHouses[numberOfHouses-1], &awayStore, &homeStore);

  awayHouses[0].assignContainerRefs(&awayStore, &homeHouses[0], &homeStore, &awayStore);
  awayHouses[numberOfHouses-1].assignContainerRefs(&awayHouses[numberOfHouses-2],
      &homeHouses[numberOfHouses-1], &homeStore, &awayStore);
}

void kalahBoard::fillHouses(vector<unsigned int> homeHouseInitialSeedCount,
    vector<unsigned int> awayHouseInitialSeedCount)
{
  if (homeHouseInitialSeedCount.size() != numberOfHouses)
    throw domain_error("home house initial seed count length doesn't match number of houses");

  if (awayHouseInitialSeedCount.size() != numberOfHouses)
    throw domain_error("away house initial seed count length doesn't match number of houses");

  for (unsigned int i = 0; i < numberOfHouses; i++)
  {
    homeHouses[i].setSeedCount(homeHouseInitialSeedCount[i]);
    awayHouses[i].setSeedCount(awayHouseInitialSeedCount[i]);
  }
}

unsigned int kalahBoard::getNumberOfHouses()
{
  return numberOfHouses;
}
