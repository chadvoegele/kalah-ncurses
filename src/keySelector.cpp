#include "keySelector.hpp"

keySelector::keySelector(humanPlayer& inHuman, int inDispRow, int inDispCol, 
    int inStdRows, int inStdCols, string inPermanentText, string inRequestText)
  : human(inHuman), dispRow(inDispRow), dispCol(inDispCol), stdRows(inStdRows),
  stdCols(inStdCols), permanentText(inPermanentText), requestText(inRequestText)
{
  m_connection = human.connect(boost::bind(&keySelector::getKey, this));
}

int keySelector::getKey()
{
  clearText();
  displayKeyRequest();

  int result = convertAsciiResultToNum(getch());

  clearText();
  redisplayText();

  return result;
}

int keySelector::convertAsciiResultToNum(int asciiResult)
{
  if (48 <= asciiResult && asciiResult <= 57)
    return asciiResult - 48;
  else
    throw new domain_error("input asciiresult was nonnumeric character");
}

void keySelector::clearText()
{
  string nameClear;
  nameClear.resize(max(permanentText.size(), requestText.size()), ' ');
  ncursesHelpers::printCenteredTextAt(nameClear, dispRow, dispCol, stdRows, stdCols);
}

void keySelector::displayKeyRequest()
{
  ncursesHelpers::printCenteredTextAt(requestText, dispRow, dispCol, stdRows, stdCols);
}

void keySelector::redisplayText()
{
  ncursesHelpers::printCenteredTextAt(permanentText, dispRow, dispCol, stdRows, stdCols);
}
