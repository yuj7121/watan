#include "criteria.h"
#include "student.h"
#include "criteria.h"

Criteria::Criteria(int index, CompletionType level, vector<Goal *> &adjGoals, Student *owner) 
    : index{index}, level{CompletionType::NONE}, adjGoals{adjGoals}, owner{nullptr} {}

bool Criteria::playCriteria(Student *player, bool startOfGame) { 
    if (getCompletionType() == CompletionType::NONE) { 
        complete(player, startOfGame); 
    } else {
        canImprove(player); 
        improve(); 
    }
}

bool Criteria::complete(Student *player, bool startOfGame) {
    if (adjacentCriteriaExist()) {
        return false; 
    }

    if (!startOfGame) { 
        if (!adjacentGoalOwner(player)) {
            return false; 
        }
    }
    addOwner(player); 
    level = CompletionType::ASSIGNMENT;
    return true; 
}

bool Criteria::canImprove(Student *player) const {
    if (level == CompletionType::EXAM) return false; 
    if (!isOwnedBy(player)) return false; 
// TODO: check if player has enough resources to upgrade
    return true; 
}

bool Criteria::improve() {
    if (level == CompletionType::ASSIGNMENT) {
        level = CompletionType::MIDTERM;
        return true;
    } else if (level == CompletionType::MIDTERM) {
        level = CompletionType::EXAM;
        return true;
    }
    return false;
}

bool Criteria::adjacentCriteriaExist() const {
    for(auto g : adjGoals) {
        if(g->checkCriteriaExist()) {
            return true; 
        }
    }
    return false; 
}

bool Criteria::adjacentGoalOwner(Student *player) const { 
    for (auto g : adjGoals) {
        if (g->isOwnedBy(player)) {
            return true;
        }
    } 
    return false;
}

int Criteria::getIndex() const { return index; } 

CompletionType Criteria::getCompletionType() const { return level; }

bool Criteria::isOwnedBy(Student* player) const { return owner == player; }

void Criteria::addOwner(Student *player) { owner = player;}


