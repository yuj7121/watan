#include "goal.h"

using namespace std; 

Goal::Goal(int index, Student* owner)
    : index{index}, owner{nullptr} {}

int Goal::getIndex() const { return index; }

Student* Goal::getOwner() const { return owner; }

bool Goal::isOwnedBy(Student* player) const {
    return owner == player;
}

void Goal::attachCriteria(Criteria* c) {
    adjCriteria.push_back(c);
}

bool Goal::checkCriteriaExist() const {
    for (auto c : adjCriteria) {
        if (c->getCompletionType() != CompletionType::NONE) {
            return true;
        }
    }
    return false;
}

bool Goal::buildGoal(Student* player) {
    bool adjacent = false;

    if (owner) {
        return false;
    }

    for (auto c : adjCriteria) {
        if (c->isOwnedBy(player) || c->adjacentGoalOwner(player)) {
            adjacent = true;
            break;
        }
    }
    if (!adjacent) return false;

    owner = player;
    return true;
}
