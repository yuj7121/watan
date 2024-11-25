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
    Goal(int index, shared_ptr<Student> owner);
    void attachCriteria(shared_ptr<Criteria> c);

    int getIndex() const; 
    Student getOwner() const; 
    void buildGoal(shared_ptr<Student> player); 
    bool isOwnedBy(shared_ptr<Student> *player) const; 
    bool checkCriteriaExist() const;

    ~Goal() = default;
};

#endif