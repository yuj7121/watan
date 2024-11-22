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

bool Criteria::canUpgrade(Student* player) const  {
    if (!isOwnedBy(player)) {
        return false; 
    } 
    return true; 
}

void Criteria::improve(Student* player) {
    if (!owner) { 
        owner = player; 
        completionType = CompletionType::ASSIGNMENT; 
    }
    
    if (canUpgrade(player)) {
        if (completionType == CompletionType::ASSIGNMENT) {
            completionType = CompletionType::MIDTERM;
        } else if (completionType == CompletionType::MIDTERM) {
            completionType = CompletionType::EXAM;
        }
    } else { 
//TODO: trying to upgrade exam, then what to do? throw?
    }
}

