#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/humanPlayer.hpp"

BOOST_AUTO_TEST_SUITE(humanPlayerTests)

BOOST_AUTO_TEST_CASE(constructor1)
{
  houseContainer cont;
  vector<houseContainer*> houseContainers;
  houseContainers.push_back(&cont);
  storeContainer scont;
  humanPlayer hp1("hp1");
  humanPlayer hp2("hp2");
  hp1.assignRefs(houseContainers, &scont, &hp2);
}

BOOST_AUTO_TEST_CASE(getName1)
{
  humanPlayer hp1("hp1");
  BOOST_CHECK_EQUAL(hp1.getName(), "hp1");
}

BOOST_AUTO_TEST_SUITE_END()

