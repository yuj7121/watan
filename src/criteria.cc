#include <iostream> 
#include <vector>
#include <memory>
#include <string>
#include "criterion.h"

using namespace std; 

Criteria::Criteria(int index, CompletionType level, vector<Goal *> &myGoals, Student *owner) 
    : index{index}, level{CompletionType::NONE}, myGoals{myGoals}, owner{nullptr} {}

bool Criteria::playCriteria(Student *player, bool startOfGame) { 
    if (getCompletionType() == NONE) { 
        complete(player, startOfGame); 
    } else {
        canUpgrade(player); 
        improve(); 
    }
}

bool Criteria::complete(Student *player, bool startOfGame) {
// TODO: check if adjacent criteria's owner == player

    if (!startOfGame) { 
// TODO: check if achieved adjacent goal's owner == player
//      - subtract resources used
    }
    addOwner(player); 
    completionType = CompletionType::ASSIGNMENT;
    return true; 
}

bool Criteria::canImprove(Student *player) const {
    if (level == EXAM) return false; 
    if (!isOwnedBy(player)) return false; 
// TODO: check if player has enough resources to upgrade
    return true; 
}

bool Criteria::improve() {
    if (completionType == CompletionType::ASSIGNMENT) {
        completionType = CompletionType::MIDTERM;
        return true;
    } else if (completionType == CompletionType::MIDTERM) {
        completionType = CompletionType::EXAM;
        return true;
    }
    return false;
}

int Criteria::getIndex() const { return index; } 

CompletionType Criteria::getCompletionType() const { return level; }

bool Criteria::isOwnedBy(Student* player) const { return owner == player; }

void Criteria::addOwner(Student *player) { owner = player;}


