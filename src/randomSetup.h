#ifndef RANDOMSETUP_H
#define RANDOMSETUP_H

#include "boardSetup.h"


class RandomSetup: public BoardSetup {
  protected:
    int seed;
    void setupResources() override;
  public:
    RandomSetup(int seed);
};

#endif