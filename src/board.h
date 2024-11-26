#ifndef BOARD_H
#define BOARD_H

#include "constants.h"
#include "subject.h"
#include "tile.h"
#include "criteria.h"
#include "goal.h"
#include "student.h"
#include "exceptions.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

using namespace std;

class BoardSetup;

class Board : public Subject {
    std::vector<std::shared_ptr<Tile>> tiles;
    std::vector<std::shared_ptr<Goal>> goals;
    std::vector<std::shared_ptr<Criteria>> criterion;
    int geesePosition;
    friend class BoardSetup;

  public:
    Board();

    void printBoard() const;
    const vector<shared_ptr<Tile>>& getTiles() const;
    int getGeese() const;

    void tileRolled(int roll);
    void buyGoal(int student, int index);
    void buyCriteria(int student, int index);
    void improveCriteria(int student, int index);
    void moveGeese(int index);
    void trade(int offeringStudent, int receivingStudent, ResourceType type);
};

#endif
