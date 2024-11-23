#ifndef GOAL_H
#define GOAL_H

#include <iostream> 
#include <vector> 
#include <string>
using namespace std; 

class Criteria;
class Player; 

class Goal {
    int index; 
    Student* owner; 
    vector<shared_ptr <Criteria>> adjCriteria;
public: 
    Goal(int index, Student* owner, vector<shared_ptr <Criteria>> adjCriteria);

    int getIndex() const; 
    Student getOwner() const; 
    void buildGoal(Student *player); 
    bool isOwnedBy(Student *player) const; 
    bool checkCriteriaExist() const;

    ~Goal() override = default;
};

#endif