#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <vector>

#include "../src/kalahBoard.hpp"

using namespace std;

struct kalahBoardTestData
{
  vector<unsigned int> homeInitialSeedCounts;
  vector<unsigned int> awayInitialSeedCounts;
};

kalahBoardTestData testData1(unsigned int numberOfHouses)
{
  vector<unsigned int> homeInitialSeedCounts;
  for (unsigned int i = 0; i < numberOfHouses; i++)
  {
    homeInitialSeedCounts.push_back(3);
  }

  vector<unsigned int> awayInitialSeedCounts;
  for (unsigned int i = 0; i < numberOfHouses; i++)
  {
    awayInitialSeedCounts.push_back(3);
  }

  kalahBoardTestData returnData;
  returnData.homeInitialSeedCounts = homeInitialSeedCounts;
  returnData.awayInitialSeedCounts = awayInitialSeedCounts;
  return returnData;
}

BOOST_AUTO_TEST_SUITE(kalahBoardTests)

BOOST_AUTO_TEST_CASE(constructor1)
{
  kalahBoardTestData testData = testData1(6);
  kalahBoard board(6);
  board.fillHouses(testData.homeInitialSeedCounts, testData.awayInitialSeedCounts);
  BOOST_CHECK_EQUAL(board.homeHouses[0].getSeedCount(), 3);
  BOOST_CHECK_EQUAL(board.homeHouses[5].getSeedCount(), 3);
  BOOST_CHECK_EQUAL(board.awayHouses[3].getSeedCount(), 3);
  BOOST_CHECK_EQUAL(board.awayHouses[0].getSeedCount(), 3);
  BOOST_CHECK_EQUAL(board.awayHouses[2].getSeedCount(), 3);
}

BOOST_AUTO_TEST_CASE(movementTest1)
{
  kalahBoardTestData testData = testData1(6);
  kalahBoard board(6);
  board.fillHouses(testData.homeInitialSeedCounts, testData.awayInitialSeedCounts);
  bool getAdditionalMove = board.homeHouses[0].initiateKalahMoveSequence();
  BOOST_CHECK_EQUAL(board.homeHouses[0].getSeedCount(), 0);
  BOOST_CHECK_EQUAL(board.homeHouses[1].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.homeHouses[2].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.homeHouses[3].getSeedCount(), 4);
  for (unsigned int i = 4; i < board.getNumberOfHouses(); i++)
  {
    BOOST_CHECK_EQUAL(board.homeHouses[i].getSeedCount(), 3);
  }
  for (unsigned int i = 0; i < board.getNumberOfHouses(); i++)
  {
    BOOST_CHECK_EQUAL(board.awayHouses[i].getSeedCount(), 3);
  }
  BOOST_CHECK_EQUAL(board.homeStore.getSeedCount(), 0);
  BOOST_CHECK_EQUAL(board.awayStore.getSeedCount(), 0);
  BOOST_CHECK_EQUAL(getAdditionalMove, false);
}

BOOST_AUTO_TEST_CASE(movementTestThroughStore)
{
  kalahBoardTestData testData = testData1(6);
  kalahBoard board(6);
  board.fillHouses(testData.homeInitialSeedCounts, testData.awayInitialSeedCounts);
  unsigned int numberOfHouses = board.getNumberOfHouses();
  bool getAdditionalMove = board.homeHouses[numberOfHouses-1].initiateKalahMoveSequence();
  BOOST_CHECK_EQUAL(board.homeHouses[numberOfHouses-1].getSeedCount(), 0);
  BOOST_CHECK_EQUAL(board.homeStore.getSeedCount(), 1);
  BOOST_CHECK_EQUAL(board.awayHouses[numberOfHouses-1].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.awayHouses[numberOfHouses-2].getSeedCount(), 4);
  for (unsigned int i = numberOfHouses-3; i != UINT_MAX; i--)
  {
    BOOST_CHECK_EQUAL(board.awayHouses[i].getSeedCount(), 3);
  }
  for (unsigned int i = 0; i < numberOfHouses-1; i++)
  {
    BOOST_CHECK_EQUAL(board.homeHouses[i].getSeedCount(), 3);
  }
  BOOST_CHECK_EQUAL(board.awayStore.getSeedCount(), 0);
  BOOST_CHECK_EQUAL(getAdditionalMove, false);
}

BOOST_AUTO_TEST_CASE(movementTestGetAddtionalMove)
{
  kalahBoardTestData testData = testData1(6);
  kalahBoard board(6);
  board.fillHouses(testData.homeInitialSeedCounts, testData.awayInitialSeedCounts);
  unsigned int numberOfHouses = board.getNumberOfHouses();
  bool getAdditionalMove = board.homeHouses[numberOfHouses-3].initiateKalahMoveSequence();
  BOOST_CHECK_EQUAL(board.homeHouses[numberOfHouses-3].getSeedCount(), 0);
  BOOST_CHECK_EQUAL(board.homeHouses[numberOfHouses-2].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.homeHouses[numberOfHouses-1].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.homeStore.getSeedCount(), 1);
  for (unsigned int i = 0; i < numberOfHouses-3; i++)
  {
    BOOST_CHECK_EQUAL(board.homeHouses[i].getSeedCount(), 3);
  }
  for (unsigned int i = 0; i < numberOfHouses; i--)
  {
    BOOST_CHECK_EQUAL(board.awayHouses[i].getSeedCount(), 3);
  }
  BOOST_CHECK_EQUAL(board.awayStore.getSeedCount(), 0);
  BOOST_CHECK_EQUAL(getAdditionalMove, true);
}

BOOST_AUTO_TEST_CASE(movementTestTakeOpponentSeeds)
{
  kalahBoardTestData testData = testData1(6);
  testData.homeInitialSeedCounts[5] = 0;
  kalahBoard board(6);
  board.fillHouses(testData.homeInitialSeedCounts, testData.awayInitialSeedCounts);
  unsigned int numberOfHouses = board.getNumberOfHouses();
  bool getAdditionalMove = board.homeHouses[2].initiateKalahMoveSequence();
  BOOST_CHECK_EQUAL(board.homeHouses[0].getSeedCount(), 3);
  BOOST_CHECK_EQUAL(board.homeHouses[1].getSeedCount(), 3);
  BOOST_CHECK_EQUAL(board.homeHouses[2].getSeedCount(), 0);
  BOOST_CHECK_EQUAL(board.homeHouses[3].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.homeHouses[4].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.homeHouses[5].getSeedCount(), 0);
  BOOST_CHECK_EQUAL(board.homeStore.getSeedCount(), 4);
  for (unsigned int i = 0; i < numberOfHouses-1; i--)
  {
    BOOST_CHECK_EQUAL(board.awayHouses[i].getSeedCount(), 3);
  }
  BOOST_CHECK_EQUAL(board.awayHouses[5].getSeedCount(), 0);
  BOOST_CHECK_EQUAL(board.awayStore.getSeedCount(), 0);
  BOOST_CHECK_EQUAL(getAdditionalMove, false);
}

BOOST_AUTO_TEST_CASE(movementTestSkipOpponentStore)
{
  kalahBoardTestData testData = testData1(6);
  testData.awayInitialSeedCounts[5] = 15;
  kalahBoard board(6);
  board.fillHouses(testData.homeInitialSeedCounts, testData.awayInitialSeedCounts);
  unsigned int numberOfHouses = board.getNumberOfHouses();
  bool getAdditionalMove = board.awayHouses[5].initiateKalahMoveSequence();
  BOOST_CHECK_EQUAL(board.awayHouses[5].getSeedCount(), 1);
  BOOST_CHECK_EQUAL(board.awayHouses[4].getSeedCount(), 5);
  BOOST_CHECK_EQUAL(board.awayHouses[3].getSeedCount(), 5);
  BOOST_CHECK_EQUAL(board.awayHouses[2].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.awayHouses[1].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.awayHouses[0].getSeedCount(), 4);
  BOOST_CHECK_EQUAL(board.awayStore.getSeedCount(), 1);
  for (unsigned int i = 0; i < numberOfHouses; i--)
  {
    BOOST_CHECK_EQUAL(board.homeHouses[i].getSeedCount(), 4);
  }
  BOOST_CHECK_EQUAL(board.homeStore.getSeedCount(), 0);
  BOOST_CHECK_EQUAL(getAdditionalMove, false);
}

BOOST_AUTO_TEST_CASE(movementTestMoveAllToStore)
{
  kalahBoardTestData testData = testData1(6);
  kalahBoard board(6);
  board.fillHouses(testData.homeInitialSeedCounts, testData.awayInitialSeedCounts);
  unsigned int numberOfHouses = board.getNumberOfHouses();
  for (unsigned int i = 0; i < numberOfHouses; i++)
  {
    board.homeHouses[i].moveAllToControlledStore();
    board.awayHouses[i].moveAllToControlledStore();
  }

  for (unsigned int i = 0; i < numberOfHouses; i++)
  {
    BOOST_CHECK_EQUAL(board.homeHouses[i].getSeedCount(), 0);
    BOOST_CHECK_EQUAL(board.awayHouses[i].getSeedCount(), 0);
  }
  BOOST_CHECK_EQUAL(board.awayStore.getSeedCount(), 18);
  BOOST_CHECK_EQUAL(board.homeStore.getSeedCount(), 18);
}

BOOST_AUTO_TEST_SUITE_END()
