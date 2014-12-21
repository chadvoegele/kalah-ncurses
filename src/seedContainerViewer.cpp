#include "seedContainerViewer.hpp"

using namespace std;

void seedContainerViewer::contructorHelper(int inHeight, int inWidth, 
    int startY, int startX, seedContainer& inSeedContainer)
{
  win = newwin(inHeight, inWidth, startY, startX);
  addBorder(win);

  noBorderHeight = inHeight - 2;
  noBorderWidth = inWidth - 2;
  maxDisplaySeeds = noBorderHeight * noBorderWidth;

  m_connection = seedCont.connect(boost::bind(&seedContainerViewer::printSeedContainer, this));
  m_connection = seedCont.connect(boost::bind(&seedContainerViewer::waitToSeeDisplay, this));
}

seedContainerViewer::seedContainerViewer(int inHeight, int inWidth, int startY, int startX,
      storeContainer& inStoreContainer) : seedCont(inStoreContainer)
{
  contructorHelper(inHeight, inWidth, startY, startX, seedCont);
}

seedContainerViewer::seedContainerViewer(int inHeight, int inWidth, int startY, int startX,
    houseContainer& inHouseContainer) : seedCont(inHouseContainer)
{
  contructorHelper(inHeight, inWidth, startY, startX, seedCont);
}

seedContainerViewer::~seedContainerViewer()
{
  m_connection.disconnect();
}

void seedContainerViewer::printSeedContainer()
{
  werase(win);
  addBorder(win);

  int seedsToDisplay = seedCont.getSeedCount();

  if (seedsToDisplay <= maxDisplaySeeds)
  {
    for (int i = 0; i < seedsToDisplay; i++)
    {
      int dispX = (i % noBorderWidth) + 1;
      int dispY = (i / noBorderWidth) + 1;
      mvwaddch(win, dispY, dispX, 'o');
    }
  }
  else if (log10(seedsToDisplay)+1 < 4)
  {
    string dispSeedsText = string("o x ");
    string dispSeedsNumText = to_string(seedsToDisplay);
    dispSeedsText = dispSeedsText + dispSeedsNumText;
    mvwaddstr(win, 1, 1, dispSeedsText.c_str());
  }
  else
  {
    throw new domain_error("Cannot display " + to_string(seedsToDisplay) + " seeds.");
  }
  wrefresh(win);
}

void seedContainerViewer::waitToSeeDisplay()
{
  usleep(500000);
}

void seedContainerViewer::addBorder(WINDOW* win)
{
  wborder(win, '|', '|', '-', '-', '/', '\\', '\\', '/');
}
