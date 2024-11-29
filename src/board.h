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

class Board {
    std::vector<std::shared_ptr<Tile>> tiles;
    std::vector<std::shared_ptr<Goal>> goals;
    std::vector<std::shared_ptr<Criteria>> criteria; // TODO replace in board criterion to criteria
    int geesePosition;
    friend class BoardSetup;

  public:
    Board();

    vector<shared_ptr<Tile>> getTiles() const;
    int getGeese() const;
    vector<shared_ptr<Criteria>> getCriteria() const; 
    vector<shared_ptr<Goal>> getGoals() const; 

    void tileRolled(const int roll);
    bool tileHasStudent(int tileIndex, shared_ptr<Student> student);
    void buyGoal(shared_ptr<Student> student, const int index);
    void sogBuyCriteria(shared_ptr<Student> student, const int index);
    void buyCriteria(shared_ptr<Student> student, const int index);
    void improveCriteria(shared_ptr<Student> student, const int index);
    void moveGeese(const int index);

    string save(); 

};


#endif
