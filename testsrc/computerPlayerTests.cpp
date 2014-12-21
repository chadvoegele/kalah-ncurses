#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../src/computerPlayer.hpp"

BOOST_AUTO_TEST_SUITE(computerPlayerTests)

BOOST_AUTO_TEST_CASE(constructor1)
{
  houseContainer cont;
  vector<houseContainer*> houseContainers;
  houseContainers.push_back(&cont);
  storeContainer scont;
  computerPlayer cp1;
  computerPlayer cp2;
  cp1.assignRefs(houseContainers, &scont, &cp2);
}

BOOST_AUTO_TEST_CASE(chooseHouseTest1)
{
  houseContainer cont;
  vector<houseContainer*> houseContainers;
  houseContainers.push_back(&cont);
  storeContainer scont;
  computerPlayer cp1;
  computerPlayer cp2;
  cp1.assignRefs(houseContainers, &scont, &cp2);
  houseContainer* chosenHouse = cp1.chooseHouse();
  BOOST_CHECK_EQUAL(chosenHouse, &cont);
}

BOOST_AUTO_TEST_CASE(chooseHouseTest2)
{
  houseContainer cont1(5);
  houseContainer cont2(5);
  vector<houseContainer*> houseContainers;
  houseContainers.push_back(&cont1);
  houseContainers.push_back(&cont2);
  storeContainer scont;
  computerPlayer cp1;
  computerPlayer cp2;
  cp1.assignRefs(houseContainers, &scont, &cp2);
  houseContainer* chosenHouse = cp1.chooseHouse();
  BOOST_CHECK_EQUAL(chosenHouse->getSeedCount(), 5);
}


BOOST_AUTO_TEST_CASE(getNameTest1)
{
  computerPlayer cp1;
  BOOST_CHECK_EQUAL(cp1.getName(), "Computer");
}

BOOST_AUTO_TEST_SUITE_END()

