#include "kalahGame.hpp"
#include <ctime>

kalahGame::kalahGame(unsigned int inNumberOfHouses, unsigned int inNumberOfSeeds, 
      Player* inHomePlayer, Player* inAwayPlayer) : board(inNumberOfHouses),
  homePlayer(inHomePlayer), awayPlayer(inAwayPlayer)
{
  kalahGame::kalahBoardInitData initData = createInitSeedCounts(inNumberOfHouses, inNumberOfSeeds);
  board.fillHouses(initData.homeInitialSeedCounts, initData.awayInitialSeedCounts);

  vector<houseContainer*> homeRefs;
  vector<houseContainer*> awayRefs;
  for (unsigned int i = 0; i < board.getNumberOfHouses(); i++)
  {
    homeRefs.push_back(&(board.homeHouses[i]));
    awayRefs.push_back(&(board.awayHouses[i]));
  }

  homePlayer->assignRefs(homeRefs, &(board.homeStore), inAwayPlayer);
  awayPlayer->assignRefs(awayRefs, &(board.awayStore), inHomePlayer);

  std::minstd_rand generator;
}

kalahGame::kalahBoardInitData kalahGame::createInitSeedCounts(unsigned int numberOfHouses, unsigned int numberOfSeeds)
{
  vector<unsigned int> homeInitialSeedCounts = vector<unsigned int>(numberOfHouses);
  vector<unsigned int> awayInitialSeedCounts = vector<unsigned int>(numberOfHouses);
  
  std::uniform_int_distribution<> dist(1, numberOfHouses * 2);
  generator.seed((unsigned int)time(NULL));

  for (unsigned int i = 0; i < numberOfSeeds; i++)
  {
    unsigned int chosenHouseIndex = dist(generator) - 1;

    if (chosenHouseIndex < numberOfHouses)
      homeInitialSeedCounts[chosenHouseIndex]++; 
    else
      awayInitialSeedCounts[chosenHouseIndex - numberOfHouses]++;
  }

  kalahGame::kalahBoardInitData initData;
  initData.homeInitialSeedCounts = homeInitialSeedCounts;
  initData.awayInitialSeedCounts = awayInitialSeedCounts;

  return initData;
}

bool kalahGame::isGameOver()
{
  bool isHomeEmpty = true;
  bool isAwayEmpty = true;
  for (unsigned int i = 0; i < board.getNumberOfHouses(); i++)
  {
    isHomeEmpty = isHomeEmpty && board.homeHouses[i].getSeedCount() == 0;
    isAwayEmpty = isAwayEmpty && board.awayHouses[i].getSeedCount() == 0;
  }

  return isHomeEmpty || isAwayEmpty;
}

void kalahGame::concludeGame()
{
  for (unsigned int i = 0; i < board.getNumberOfHouses(); i++)
  {
    board.homeHouses[i].moveAllToControlledStore();
    board.awayHouses[i].moveAllToControlledStore();
   }
}

kalahGame::kalahGameStatus kalahGame::startGame()
{
Player* activePlayer = homePlayer;
while(!isGameOver())
{
  houseContainer* chosenHouse = activePlayer->chooseHouse();
  bool getAdditionalMove = chosenHouse->initiateKalahMoveSequence();
  if (!getAdditionalMove)
    activePlayer = activePlayer->getOpponent();
}
concludeGame();

return buildResults();
}

kalahGame::kalahGameStatus kalahGame::buildResults()
{
  kalahGameStatus status;
  status.homeNumberOfSeeds = homePlayer->getStore()->getSeedCount();
  status.awayNumberOfSeeds = awayPlayer->getStore()->getSeedCount();
  status.homeName = homePlayer->getName();
  status.awayName = awayPlayer->getName();

  return status;
}
