#ifndef GOAL_H
#define GOAL_H

#include <iostream> 
#include <vector> 
#include <string>
#include "subject.h"

class Criteria; 
class Student; 

using namespace std; 

class Goal {
    int index;
    Student *owner;
    vector<std::shared_ptr<Criteria>> adjCriteria;

public:
    Goal(int index, Student *owner = nullptr);

    int getIndex() const;
    Student *getOwner() const;
    bool isOwnedBy(Student *player) const;
    bool checkCriteriaExist() const;
    void setOwner(Student *s); 
    
    void attachCriteria(std::shared_ptr<Criteria> c);
    void detachCriteria(std::shared_ptr<Criteria> c); 
    bool playGoal(Student *player);
    string info() const;

    
    ~Goal() = default; 
};

#endif