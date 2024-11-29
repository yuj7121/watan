#ifndef BOARDSETUP_H
#define BOARDSETUP_H

#include "constants.h"
#include "tile.h"
#include "goal.h"
#include "criteria.h"
#include <vector>
#include <string>
#include <utility>
#include <memory>

class Board;
class Tile;
class Goal;
class Criteria;

class BoardSetup {
  protected:
    int resourceTypes[NUM_TILES];
    int resourceValues[NUM_TILES];
    virtual void setupResources() = 0;
  public:
    BoardSetup();
    void setup(std::shared_ptr<Board> b);
};

#endif

