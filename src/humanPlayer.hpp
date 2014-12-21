#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <vector>

#include "houseContainer.hpp"
#include "Player.hpp"

using namespace std;

class humanPlayer : public Player
{

public:
  typedef boost::signals2::signal<int ()>  signal_t;

  humanPlayer(string inName);
  virtual houseContainer* chooseHouse();
  boost::signals2::connection connect(const signal_t::slot_type &subscriber);

private:
  signal_t m_signal;

};

#endif
