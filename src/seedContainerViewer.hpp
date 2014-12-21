#ifndef SEED_CONTAINER_VIEWER_H
#define SEED_CONTAINER_VIEWER_H

#include <ncurses.h>
#include <boost/signals2.hpp>
#include <string>
#include <time.h>
#include <cmath>

#include "seedContainer.hpp"
#include "houseContainer.hpp"
#include "storeContainer.hpp"

class seedContainerViewer
{

public:
  seedContainerViewer(int inHeight, int inWidth, int startY, int startX,
      storeContainer& inStoreContainer);
  seedContainerViewer(int inHeight, int inWidth, int startY, int startX,
      houseContainer& inHouseContainer);
  void printSeedContainer();
  void waitToSeeDisplay();
  ~seedContainerViewer();

private:
  void contructorHelper(int inHeight, int inWidth, 
      int startY, int startX, seedContainer& inSeedContainer);
  void addBorder(WINDOW* win);

  WINDOW* win;
  seedContainer& seedCont;
  int maxDisplaySeeds;
  int noBorderHeight;
  int noBorderWidth;
  boost::signals2::connection m_connection;

};

#endif

