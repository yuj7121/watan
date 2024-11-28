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

class Criteria : public Subject {
    int index;
    CompletionType level;
    vector<shared_ptr<Goal>> adjGoals;
    Student *owner;
    bool startOfGame;
public:
    Criteria(int index, CompletionType level, vector<shared_ptr<Goal>> &adjGoals, Student *owner);
    bool playCriteria(Student *player, bool startOfGame);

    int getIndex() const;
    Student* getOwner() const;
    int getCompletionLevel() const;
    bool isOwnedBy(Student *player) const;
    bool nbrGoalOwnedBy(Student *player) const;
    bool adjacentGoalOwner(Student *player) const;

    void notifyObservers() override;
    string print() const; 

    ~Criteria() = default;
private:
    void addOwner(Student *player);
    bool adjacentCriteriaExist() const;
    bool complete(Student *player, bool startOfGame);
    bool canImprove(Student *player) const;
    bool improve();
};

#endif