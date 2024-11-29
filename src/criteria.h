#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "constants.h"
#include "subject.h"
#include "observer.h"

using namespace std;

class Student;
class Goal;
class Tile;

class Criteria {
    int index;
    CompletionType level;
    vector<shared_ptr<Goal>> adjGoals;
    shared_ptr<Student> owner;
    bool startOfGame;
public:
    Criteria(int index, CompletionType level, vector<shared_ptr<Goal>> &adjGoals, shared_ptr<Student>owner);
    bool playCriteria(shared_ptr<Student> player, bool startOfGame);

    int getIndex() const;
    shared_ptr<Student> getOwner() const;
    int getCompletionLevel() const;
    bool isOwnedBy(shared_ptr<Student> player) const;
    bool nbrGoalOwnedBy(shared_ptr<Student> player) const;
    bool adjacentGoalOwner(shared_ptr<Student> player) const;

    string info() const; 
    ~Criteria() = default;
private:
    void addOwner(shared_ptr<Student> player);
    bool adjacentCriteriaExist() const;
    bool complete(shared_ptr<Student> player, bool startOfGame);
    bool canImprove(shared_ptr<Student> player) const;
    bool improve();
};

#endif