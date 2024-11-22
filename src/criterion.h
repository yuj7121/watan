#ifndef CRITERION_H
#define CRITERION_H

#include <iostream> 
#include <vector>
#include <memory>
#include <string>

using namespace std; 

class Student; 
class Goals; 

enum class CompletionType {
    NONE,
    ASSIGNMENT,
    MIDTERM,
    EXAM
};

class Criteria { 
    int index; 
    CompletionType level; 
    std::vector<int> AdjacentCriteria; // just need int, since only used to see if adjacent, dont need actual Criteria
    Student *owner; 
public: 
    Criteria(int index);  

    int getIndex() const;
    CompletionType getCompletionType() const;
    string getOwner() const;
    
    bool isAdjacent(); 
    bool isOwnedBy(Student* player) const;
    void setOwner(Student* player); 
    void improve(Student* player); 

    // IMPLEMENT DESTRUCTOR

}; 

#endif