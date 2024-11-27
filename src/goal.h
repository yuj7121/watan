#ifndef GOAL_H
#define GOAL_H

#include <iostream> 
#include <vector> 
#include <string>

class Criteria; 
class Student; 

using namespace std; 

class Goal {
    int index;
    Student* owner;
    vector<Criteria *> adjCriteria;

public:
    Goal(int index, Student* owner);

    int getIndex() const;
    Student* getOwner() const;
    bool isOwnedBy(Student* player) const;
    bool checkCriteriaExist() const;
    
    void attachCriteria(Criteria *c);
    bool playGoal(Student* player);
    ~Goal() = default;
};

#endif