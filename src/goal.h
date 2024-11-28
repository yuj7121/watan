#ifndef GOAL_H
#define GOAL_H

#include <iostream> 
#include <vector> 
#include <string>
#include "subject.h"

class Criteria; 
class Student; 

using namespace std; 

class Goal : public Subject {
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
    void detachCriteria(Criteria *c); 
    bool playGoal(Student* player);
    void notifyObservers() override;
    
    ~Goal() = default;
};

#endif