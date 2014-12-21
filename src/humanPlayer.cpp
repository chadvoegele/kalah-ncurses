#include "humanPlayer.hpp"

humanPlayer::humanPlayer(string inName) 
{
  name = inName;
}

houseContainer* humanPlayer::chooseHouse()
{
  unsigned int selectedHouse = m_signal().get();
  while (!(1 <= selectedHouse && selectedHouse <= controlledHouses.size()))
  {
    selectedHouse = m_signal().get();
  }

  return controlledHouses[selectedHouse-1];
}

boost::signals2::connection humanPlayer::connect(const signal_t::slot_type &subscriber)
{
  return m_signal.connect(subscriber);
}
