#ifndef NCURSES_HELPERS_H
#define NCURSES_HELPERS_H

#include <stdexcept>

#include <ncurses.h>
#include <string>

using namespace std;

class ncursesHelpers
{

public:
  static void printCenteredTextAt(string text, int row, int col, int stdRows, int stdCols);
  static void printCenteredText(string text, int stdRows, int stdCols);
};

#endif

