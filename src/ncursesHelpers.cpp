#include "ncursesHelpers.hpp"

void ncursesHelpers::printCenteredTextAt(string text, int row, int col, int stdRows, int stdCols)
{
  if (row > stdRows)
    throw new domain_error("trying to print beyond the screen");

  mvprintw(row, col - text.length()/2, "%s", text.c_str());
  refresh();
}

void ncursesHelpers::printCenteredText(string text, int stdRows, int stdCols)
{
  printCenteredTextAt(text, stdRows/2, stdCols/2, stdRows, stdCols);
}

