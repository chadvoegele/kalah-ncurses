#include <stdexcept>

#include "kalahGameController.hpp"

using namespace std;

kalahGameController::kalahGameController()
{
  // ncurses screen set up
  initscr();
  cbreak();
  nodelay(stdscr, FALSE);
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  getmaxyx(stdscr, stdRows, stdCols);

  if (stdRows < 24 || stdCols < 80)
    throw new domain_error("screen must be at least 24 rows by 80 columns");
}

kalahGameController::~kalahGameController()
{
  endwin();
}

string kalahGameController::getPlayerName()
{
  string getNameRequest = "Please enter your name: ";
  ncursesHelpers::printCenteredText(getNameRequest, stdRows, stdCols);

  echo();
  char readChars[80];
  getstr(readChars);
  noecho();

  string readName = string(readChars);

  return readName;
}

void kalahGameController::start()
{
  string name = getPlayerName();
  erase();
  refresh();

  kalahGame::kalahGameStatus status = runGame(name);
  erase();
  refresh();

  displayResults(status);
  getch();
}

void kalahGameController::buildViewers(kalahBoard& board, vector<seedContainerViewer>& allViewers)
{
  int totalContainers = board.getNumberOfHouses()*2 + 2;
  allViewers.reserve(totalContainers);

  allViewers.emplace_back(24, 9, 0, 70, board.homeStore);
  allViewers.emplace_back(24, 9, 0, 0, board.awayStore);
  for (unsigned int i = 0; i < board.getNumberOfHouses(); i++)
  {
    allViewers.emplace_back(11, 9, 13, 10*(i+1), board.homeHouses[i]);
    allViewers.emplace_back(11, 9, 0, 10*(i+1), board.awayHouses[i]);
  }

  for (vector<seedContainerViewer>::iterator iter = allViewers.begin();
      iter != allViewers.end(); iter++)
    iter->printSeedContainer();
}

kalahGame::kalahGameStatus kalahGameController::runGame(string name)
{
  humanPlayer human(name);
  string requestText = "Enter a selection from 1 to " + printInt(6);
  keySelector humanSelector(human, 12, 40, stdRows, stdCols, human.getName(), requestText);

  computerPlayer computer;
  kalahGame game(6, 30, &human, &computer);

  ncursesHelpers::printCenteredTextAt(human.getName(), 12, 40, stdRows, stdCols);
  ncursesHelpers::printCenteredTextAt(computer.getName(), 11, 40, stdRows, stdCols);
  vector<seedContainerViewer> allViewers;
  buildViewers(game.board, allViewers);

  return game.startGame();
}

string kalahGameController::printInt(int number)
{
  return to_string(number);
}

void kalahGameController::displayResults(kalahGame::kalahGameStatus status)
{
  string result;
  if (status.homeNumberOfSeeds == status.awayNumberOfSeeds)
  {
    result = status.homeName + " tied " + status.awayName + " with "
      + printInt(status.homeNumberOfSeeds) + " seeds each!";
  } 
  else if (status.homeNumberOfSeeds > status.awayNumberOfSeeds)
  {
    result = status.homeName + " beat " + status.awayName + " with "
      + printInt(status.homeNumberOfSeeds) + " to seeds " + printInt(status.awayNumberOfSeeds)
      + " seeds!";
  }
  else
  {
    result = status.awayName + " beat " + status.homeName + " with "
      + printInt(status.awayNumberOfSeeds) + " to seeds " + printInt(status.homeNumberOfSeeds)
      + " seeds!";
  }
  ncursesHelpers::printCenteredText(result, stdRows, stdCols);
}
