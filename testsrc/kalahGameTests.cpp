#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/kalahGame.hpp"
#include "../src/computerPlayer.hpp"

BOOST_AUTO_TEST_SUITE(storeContainerTests)

BOOST_AUTO_TEST_CASE(gameTest1)
{
  computerPlayer cp1;
  computerPlayer cp2;
  kalahGame game(6, 30, &cp1, &cp2);
  kalahGame::kalahGameStatus gameStatus = game.startGame();
  BOOST_CHECK_EQUAL(gameStatus.homeNumberOfSeeds >= 0, true);
  BOOST_CHECK_EQUAL(gameStatus.awayNumberOfSeeds >= 0, true);
}

BOOST_AUTO_TEST_CASE(gameTest2)
{
  computerPlayer cp1;
  computerPlayer cp2;
  kalahGame game(6, 100, &cp1, &cp2);
  kalahGame::kalahGameStatus gameStatus = game.startGame();
  BOOST_CHECK_EQUAL(gameStatus.homeNumberOfSeeds >= 0, true);
  BOOST_CHECK_EQUAL(gameStatus.awayNumberOfSeeds >= 0, true);
}

BOOST_AUTO_TEST_CASE(isOverTest1)
{
  computerPlayer cp1;
  computerPlayer cp2;
  kalahGame game(6, 100, &cp1, &cp2);
  for (unsigned int i = 0; i < game.board.getNumberOfHouses(); i++)
  {
    game.board.homeHouses[i].setSeedCount(0);
  }
  BOOST_CHECK_EQUAL(game.isGameOver(), true);
}

BOOST_AUTO_TEST_CASE(isOverTest2)
{
  computerPlayer cp1;
  computerPlayer cp2;
  kalahGame game(6, 100, &cp1, &cp2);
  for (unsigned int i = 0; i < game.board.getNumberOfHouses(); i++)
  {
    game.board.awayHouses[i].setSeedCount(0);
  }
  BOOST_CHECK_EQUAL(game.isGameOver(), true);
}

BOOST_AUTO_TEST_SUITE_END()

