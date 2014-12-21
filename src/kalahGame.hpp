#ifndef KALAH_GAME_H
#define KALAH_GAME_H

#include <random>

#include "Player.hpp"
#include "kalahBoard.hpp"

class kalahGame
{

public:
  kalahGame(unsigned int numberOfHousesIn, unsigned int inNumberOfSeeds, 
      Player* inHomePlayer, Player* inAwayPlayer);
   
  struct kalahGameStatus
  {
    string homeName;
    string awayName;
    unsigned int homeNumberOfSeeds;
    unsigned int awayNumberOfSeeds;
  };
  kalahGameStatus startGame();
  bool isGameOver();
  kalahBoard board;

private:
  struct kalahBoardInitData
  {
    vector<unsigned int> homeInitialSeedCounts;
    vector<unsigned int> awayInitialSeedCounts;
  };
  kalahBoardInitData createInitSeedCounts(unsigned int numberOfHouses, unsigned int numberOfSeeds);
  void concludeGame();
  kalahGameStatus buildResults();

  Player* homePlayer;
  Player* awayPlayer;

  std::minstd_rand generator;
};

#endif

