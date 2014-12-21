#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/storeContainer.hpp"

BOOST_AUTO_TEST_SUITE(storeContainerTests)

BOOST_AUTO_TEST_CASE(constructor1)
{
  storeContainer cont;
  BOOST_CHECK_EQUAL(cont.getSeedCount(), 0);
}

BOOST_AUTO_TEST_CASE(setTest1)
{
  storeContainer cont;
  cont.setSeedCount(5);
  BOOST_CHECK_EQUAL(cont.getSeedCount(), 5);
}

BOOST_AUTO_TEST_CASE(isStoreTest)
{
  storeContainer cont;
  BOOST_CHECK_EQUAL(cont.isStore(), true);
}

BOOST_AUTO_TEST_CASE(takeOneSeedTest)
{
  storeContainer cont;
  cont.setSeedCount(5);
  int seedsLeft = cont.takeOneSeed(6);
  BOOST_CHECK_EQUAL(cont.getSeedCount(), 6);
  BOOST_CHECK_EQUAL(seedsLeft, 5);
}

BOOST_AUTO_TEST_SUITE_END()
