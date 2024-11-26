#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "board.h"
#include "constants.h"
#include "tile.h"
#include "criteria.h"
#include "goal.h"
#include "student.h"
#include "exceptions.h"

using namespace std;

Board::Board() : geesePosition(NOT_IN_PLAY) {}

const std::vector<std::shared_ptr<Tile>>& Board::getTiles() const {
    return tiles;
}

int Board::getGeese() const {
    return geesePosition;
}

void Board::tileRolled(const int roll) {
    for (unsigned int i = 0; i < tiles.size(); i++) {
        const auto &tile = tiles[i];
        if (tile->getValue() == roll && tile->getResourceType() != ResourceType::NETFLIX) {
            const auto &criteriaIndices = CRITERIA_PER_TILE[i];
            for (int criterionIndex : criteriaIndices) {
                const auto &crit = criterion[criterionIndex];
                if (crit->getOwner()) {
                    crit->getOwner()->addResource(tile->getResourceType());
                }
            }
        }
    }
}

void Board::buyGoal(shared_ptr<Student> student, const int index) {
    auto &goal = goals[index];
    if (goal->getOwner() != nullptr) {
        throw AlreadyOwnedException("Goal is already owned!");
    }
    if (student->hasResources({ResourceType::STUDY, ResourceType::TUTORIAL})) {
        goal->buildGoal(student);
        student->addGoal(index);
        student->removeResources({ResourceType::STUDY, ResourceType::TUTORIAL});
    } else {
        throw InsufficientResourcesException("Not enough resources to buy goal!");
    }
}

void Board::buyCriteria(shared_ptr<Student> student, const int index) {
    auto &crit = criterion[index];
    if (crit->getOwner() != nullptr) {
        throw AlreadyOwnedException("Criterion is already owned!");
    }
    if (student->hasResources({ResourceType::CAFFEINE, ResourceType::LAB,
                                         ResourceType::LECTURE, ResourceType::TUTORIAL})) {
        crit->playCriteria(student, false);
        student->addCriterion(index);
        student->removeResources({ResourceType::CAFFEINE, ResourceType::LAB,
                                            ResourceType::LECTURE, ResourceType::TUTORIAL});
    } else {
        throw InsufficientResourcesException("Not enough resources to buy criterion!");
    }
}

void Board::improveCriteria(shared_ptr<Student> student, const int index) {
    auto &crit = criterion[index];
    if (crit->getOwner() != student) {
        throw InvalidCriterionImprovementException("Criterion is not owned by this student!");
    }
    if (crit->getCompletionType() == CompletionType::EXAM) {
        throw InvalidCriterionImprovementException("Criterion is already fully upgraded!");
    }
    vector<ResourceType> cost;
    if (crit->getCompletionType() == CompletionType::ASSIGNMENT) {
        cost = {ResourceType::LECTURE, ResourceType::LECTURE, ResourceType::STUDY, ResourceType::STUDY, ResourceType::STUDY};
    } else if (crit->getCompletionType() == CompletionType::MIDTERM) {
        cost = {ResourceType::CAFFEINE, ResourceType::CAFFEINE, ResourceType::CAFFEINE,
                ResourceType::LAB, ResourceType::LAB, ResourceType::LECTURE,
                ResourceType::LECTURE, ResourceType::TUTORIAL, ResourceType::STUDY, ResourceType::STUDY};
    }
    if (student->hasResources(cost)) {
        crit->playCriteria(student, false);
        student->removeResources(cost);
    } else {
        throw InsufficientResourcesException("Not enough resources to improve criterion!");
    }
}

void Board::moveGeese(const int index) {
    if (index == geesePosition) {
        throw InvalidGeesePlacementException("Geese are already on this tile!");
    }
    geesePosition = index;
}

void Board::trade(shared_ptr<Student> offeringStudent, shared_ptr<Student> receivingStudent,
const ResourceType offered, const ResourceType requested) {
    if (offeringStudent->getResource(offered) == 0) {
        throw InsufficientResourcesException("Offering student does not have the resource to trade!");
    }
    if (receivingStudent->getResource(requested) == 0) {
        throw InsufficientResourcesException("Receiving student does not have the requested resource!");
    }
    offeringStudent->removeResource(offered);
    offeringStudent->addResource(requested);
    receivingStudent->removeResource(requested);
    receivingStudent->addResource(offered);
}