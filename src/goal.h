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
    vector<Criteria *> adjCriteria;
public: 
    Goal(int index, Student* owner);

    int getIndex() const; 
    Student getOwner() const; 
    void buildGoal(Student *player); 
    bool isOwnedBy(Student *player) const; 

    bool checkCriteriaExist() const;
    void attachCriteria(Criteria *c);
    void detachCriteria(Criteria *c);

    ~Goal() override = default;
};



#endif