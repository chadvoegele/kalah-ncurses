#ifndef KEY_SELECTOR_H
#define KEY_SELECTOR_H

#include <ncurses.h>
#include <boost/signals2.hpp>
#include <string>
#include <algorithm>

#include "kalahGameController.hpp"
#include "humanPlayer.hpp"

class keySelector
{

public:
  keySelector(humanPlayer& inHuman, int inDispRow, int inDispCol, int inStdRows, int inStdCols,
      string inPermanentText, string inRequestText);
  int getKey();

private:
  int convertAsciiResultToNum(int asciiResult);
  void clearText();
  void displayKeyRequest();
  void redisplayText();
  humanPlayer& human;
  int dispRow;
  int dispCol;
  int stdRows;
  int stdCols;
  string permanentText;
  string requestText;
  boost::signals2::connection m_connection;

};

#endif


