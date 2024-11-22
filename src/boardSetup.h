#ifndef BOARDSETUP_H
#define BOARDSETUP_H

#include "board.h"
#include "tile.h"
//#include "goal.h"
//#include "criteria.h"
#include <vector>
#include <string>
#include <utility>
#include <memory>

using namespace std;

enum class Colour { BLUE, RED, ORANGE, YELLOW };

class Tile;
class Goal;
class Criteria;

class BoardSetup {
  protected:
    const static int DEFUALT_TILES = 19;
    int resourceTypes[DEFUALT_TILES];
    int resourceValues[DEFUALT_TILES];
    virtual void setupResources() = 0;
  public:
    BoardSetup();
    void setup(shared_ptr<Board> b);
};

#endif