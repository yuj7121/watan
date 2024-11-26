#ifndef RANDOMSETUP_H
#define RANDOMSETUP_H

#include "boardSetup.h"
#include <algorithm>
#include <random>
#include <vector>

class RandomSetup: public BoardSetup {
  protected:
    std::default_random_engine rng;
    int seed;
    void setupResources() override;
  public:
    RandomSetup(int seed);
};

#endif