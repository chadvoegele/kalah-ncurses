#include <stdexcept>

#include "seedContainer.hpp"

using namespace std;

unsigned int seedContainer::getSeedCount() const
{
  return seedCount;
}

void seedContainer::setSeedCount(unsigned int inSeedCount)
{
  seedCount = inSeedCount;
  m_signal();
}

unsigned int seedContainer::takeOneSeed(unsigned int incomingSeeds)
{
  if (!(incomingSeeds > 0))
    throw domain_error("cannot take a seed if there are none");

  setSeedCount(getSeedCount() + 1);
  return incomingSeeds - 1;
}


boost::signals2::connection seedContainer::connect(const signal_t::slot_type &subscriber)
{
  return m_signal.connect(subscriber);
}
