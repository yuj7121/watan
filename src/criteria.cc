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

bool Criteria::isAdjacentEdge() {
    // TODO: do this function
}

bool Criteria::isAdjacentVertex() {
    // TODO: do this function
}

bool Criteria::canUpgrade(Student* player) const  {
    if (!isOwnedBy(player)) {
        return false; 
    } 
    return true; 
}

/*
For a student to complete a criterion, the following two conditions must be met:
• No adjacent criterion is completed.
• It is either the beginning of the game, or they have achieved a goal that is adjacent to the criterion.
*/

// maybe if upgraded, then it returns true, so board knows that it needs to print new edge -> require print method here
void Criteria::improve(Student* player) {
    if (!owner && !isAdjacentEdge && isAdjacentGoal) { 
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

