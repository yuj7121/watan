#ifndef GOAL_H
#define GOAL_H

#include <iostream> 
#include <vector> 
#include <string>
#include <memory> 

using namespace std; 

class Criteria;
class Player; 
class Student; 

class Goal {
    int index; 
    Student* owner; 
    vector<Criteria *> adjCriteria;
public: 
    Goal(int index, Student* owner);
    void attachCriteria(Criteria * c);

    int getIndex() const; 
    Student getOwner() const; 
    bool buildGoal(Student* player); 
    bool isOwnedBy(Student* player) const; 
    bool checkCriteriaExist() const;

    ~Goal() = default;
};

#endif