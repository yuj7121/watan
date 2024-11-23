#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream> 
#include <vector>
#include <memory>
#include <string>

using namespace std; 

class Student; 
class Goal; 
class Tile; 

enum class CompletionType {
    NONE, 
    ASSIGNMENT,
    MIDTERM,
    EXAM
};

class Criteria { 
    int index; 
    CompletionType level; 
    vector<Goal *> myGoals;
    Student *owner; 
    bool startOfGame;
public: 
    Criteria(int index, CompletionType level, vector<Goal *> &myGoals, Student *owner);
    bool playCriteria(Student *player, bool startOfGame);

    int getIndex() const;
    CompletionType getCompletionType() const;
    bool isOwnedBy(Student *player) const;
    bool nbrGoalOwnedBy(Student *player) const;
    void addOwner(Student *player); 

    virtual ~Criteria() = default;
private: 
    bool complete(Student *player, bool startOfGame); 
    bool canImprove(Student *player) const;
    bool improve(); 
}; 

#endif