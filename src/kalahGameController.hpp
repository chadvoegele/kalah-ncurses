#ifndef KALAH_GAME_CONTROLLER_H
#define KALAH_GAME_CONTROLLER_H

#include <ncurses.h>
#include <string>

#include "kalahGame.hpp"
#include "humanPlayer.hpp"
#include "keySelector.hpp"
#include "computerPlayer.hpp"
#include "seedContainerViewer.hpp"
#include "ncursesHelpers.hpp"

using namespace std;

class kalahGameController
{

public:
  kalahGameController();
  ~kalahGameController();
  void start();
   
private:
  string getPlayerName();
  void buildViewers(kalahBoard& board, vector<seedContainerViewer>& allViewers);
  kalahGame::kalahGameStatus runGame(string name);
  string printInt(int number);
  void displayResults(kalahGame::kalahGameStatus status);
  int stdRows;
  int stdCols;

};

#endif


