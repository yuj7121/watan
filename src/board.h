#ifndef BOARD_H
#define BOARD_H

#include "boardSetup.h"
#include "constants.h"

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>


class Tile;
class Goal;
class Criteria;

class Board : public Subject {
    vector<shared_ptr<Tile>> tiles;
    vector<shared_ptr<Goal>> goals;
    vector<shared_ptr<Criteria>> criterion;
    int geesePosition;
    friend class BoardSetup;

public:
    Board();

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
