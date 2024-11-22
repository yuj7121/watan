#include <iostream> 
#include <vector>
#include <memory>
#include <string>
#include "criterion.h"

using namespace std; 

Criteria::Criteria(int index) : index{index}, level{CompletionType::NONE}, owner{nullptr} {}

int Criteria::getIndex() const { return index; } 

CompletionType Criteria::getCompletionType() const { return level; }

Student Criteria::getOwner() const {
    // CHECK: this function needed?
    return owner; 
}

bool Criteria::isOwnedBy(Student* player) const {
    // CHECK: this function needed?
    return owner==player;
}

bool isAdjacent() {
    // TODO: do this function
}

void improve(Student* player) {
    // CHECK: where to deal with trying to upgrade if already EXAM
    if (!owner) { 
        owner = player; 
        completionType = CompletionType::ASSIGNMENT; 
    }
    
    if (completionType == CompletionType::ASSIGNMENT) {
        completionType = CompletionType::MIDTERM;
    } else if (completionType == CompletionType::MIDTERM) {
        completionType = CompletionType::EXAM;
    }
}

