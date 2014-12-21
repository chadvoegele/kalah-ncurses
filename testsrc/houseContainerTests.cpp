#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/houseContainer.hpp"

BOOST_AUTO_TEST_SUITE(houseContainerTests)

BOOST_AUTO_TEST_CASE(constructor1)
{
  houseContainer cont;
  BOOST_CHECK_EQUAL(cont.getSeedCount(), 0);
}

BOOST_AUTO_TEST_CASE(setTest1)
{
  houseContainer cont;
  cont.setSeedCount(5);
  BOOST_CHECK_EQUAL(cont.getSeedCount(), 5);
}

BOOST_AUTO_TEST_CASE(isStoreTest)
{
  houseContainer cont;
  BOOST_CHECK_EQUAL(cont.isStore(), false);
}

BOOST_AUTO_TEST_CASE(takeOneSeedTest)
{
  houseContainer cont;
  cont.setSeedCount(5);
  int seedsLeft = cont.takeOneSeed(6);
  BOOST_CHECK_EQUAL(cont.getSeedCount(), 6);
  BOOST_CHECK_EQUAL(seedsLeft, 5);
}

BOOST_AUTO_TEST_SUITE_END()
