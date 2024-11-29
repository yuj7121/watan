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
    shared_ptr<Student> owner;
    vector<std::shared_ptr<Criteria>> adjCriteria;

public:
    Goal(int index, shared_ptr<Student> owner = nullptr);

    int getIndex() const;
    shared_ptr<Student> getOwner() const;
    bool isOwnedBy(shared_ptr<Student> player) const;
    bool checkCriteriaExist() const;
    void setOwner(shared_ptr<Student> s); 
    
    void attachCriteria(std::shared_ptr<Criteria> c);
    void detachCriteria(std::shared_ptr<Criteria> c); 
    bool playGoal(shared_ptr<Student> player);
    string info() const;

    
    ~Goal() = default; 
};

#endif