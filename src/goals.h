#ifndef GOALS_H
#define GOALS_H

#include <iostream> 
#include <vector> 
#include <string>
using namespace std; 

class Criteria;

class Goals {
    int index; 
    Student* owner; 
    vector<int> Adjacent;
public: 
    Goals(int index); 
    int getIndex() const; 
    Student getOwner() const; 
    void buildGoal(Student *player); 
    bool isOwnedBy(Student *player); 
    
    void attachCriteria(Criteria *c);
    void detachCriteria(Criteria *c);

};



#endif