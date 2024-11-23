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
// vector<int> AdjacentCriteria; // just need int, since only used to see if adjacent, dont need actual Criteria
    Student *owner; 
public: 
    Criteria(int index);  

    int getIndex() const;
    CompletionType getCompletionType() const;
    Student getOwner() const;
    
    bool isAdjacentEdge(); 
    bool isAdjacentVertex(); 
    bool isOwnedBy(Student* player) const;
    void improve(Student* player); 
    bool canUpgrade(Student* player) const; 
    // IMPLEMENT DESTRUCTOR

}; 

#endif