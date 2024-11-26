#include "criteria.h"

Criteria::Criteria(int index, CompletionType level, vector<shared_ptr<Goal>> &adjGoals, shared_ptr<Student> owner)
    : index{index}, level{CompletionType::NONE}, adjGoals{adjGoals}, owner{nullptr} {}

bool Criteria::playCriteria(shared_ptr<Student> player, bool startOfGame) {
    if (getCompletionType() == CompletionType::NONE) {
        return complete(player, startOfGame);
    } else {
        if (canImprove(player)) {
            return improve();
        }
    }
    return false;
}

bool Criteria::complete(shared_ptr<Student> player, bool startOfGame) {
    if (adjacentCriteriaExist()) {
        return false;
    }

    if (!startOfGame && !adjacentGoalOwner(player)) {
        return false;
    }

    addOwner(player);
    level = CompletionType::ASSIGNMENT;
    return true;
}

bool Criteria::canImprove(shared_ptr<Student> player) const {
    if (level == CompletionType::EXAM) return false;
    if (!isOwnedBy(player)) return false;
    // TODO: Check if player has enough resources to upgrade
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
    for (auto &g : adjGoals) {
        if (g->checkCriteriaExist()) {
            return true;
        }
    }
    return false;
}

bool Criteria::adjacentGoalOwner(shared_ptr<Student> player) const {
    for (auto &g : adjGoals) {
        if (g->isOwnedBy(player)) {
            return true;
        }
    }
    return false;
}

int Criteria::getIndex() const { return index; }

shared_ptr<Student> Criteria::getOwner() const { return owner; }

CompletionType Criteria::getCompletionType() const { return level; }

bool Criteria::isOwnedBy(shared_ptr<Student> player) const { return owner == player; }

void Criteria::addOwner(shared_ptr<Student> player) { owner = player; }
