#ifndef SEED_CONTAINER_H
#define SEED_CONTAINER_H

#include <boost/signals2.hpp>

class seedContainer
{

public:
  typedef boost::signals2::signal<void ()>  signal_t;

  virtual ~seedContainer() {}
  virtual bool isStore() const = 0;
  virtual void setSeedCount(unsigned int inSeedCount);
  virtual unsigned int getSeedCount() const;
  virtual unsigned int takeOneSeed(unsigned int incomingSeeds);
  // return bool indicating whether or not the player receives an additional
  // move
  virtual bool kalahMoveSequence(unsigned int incomingSeeds,
                                          bool isOwnedByActivePlayer) = 0;
  virtual boost::signals2::connection connect(const signal_t::slot_type &subscriber);

protected:
  unsigned int seedCount;
  seedContainer* nextContainer;
  signal_t m_signal;

};

#endif
