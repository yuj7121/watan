#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "constants.h"
#include "tile.h"
#include "criterion.h"
#include "goal.h"
#include "student.h"
#include "exceptions.h"

using namespace std;

Board::Board() : geesePosition(NOT_IN_PLAY) {}

void Board::printBoard() const {
    for (const auto &tile : tiles) {
        cout << "Tile: " << tile->getIndex() << " Resource: " << tile->getResource()
             << " Value: " << tile->getValue() << endl;
    }
}

const std::vector<std::shared_ptr<Tile>>& Board::getTiles() const {
    return tiles;
}

int Board::getGeese() const {
    return geesePosition;
}

void Board::tileRolled(int roll) {
    cout << "Rolled: " << roll << endl;
    for (const auto &tile : tiles) {
        if (tile->getValue() == roll && tile->getResource() != ResourceType::NETFLIX) {
            for (const auto &criterion : tile->getCriterias()) {
                if (criterion->getOwner()) {
                    int resources = criterion->getUpgradeLevel();
                    criterion->getOwner()->addResource(tile->getResource(), resources);
                }
            }
        }
    }
}

void Board::buyGoal(int student, int index) {
    auto &goal = goals[index];
    if (goal->getOwner() != nullptr) {
        throw AlreadyOwnedException("Goal is already owned!");
    }
    if (students[student]->hasResources({ResourceType::STUDY, ResourceType::TUTORIAL})) {
        goal->setOwner(students[student].get());
        students[student]->addGoal(index);
        students[student]->removeResources({ResourceType::STUDY, ResourceType::TUTORIAL});
        cout << "Goal " << index << " acquired by student " << student << endl;
    } else {
        throw InsufficientResourcesException("Not enough resources to buy goal!");
    }
}

void Board::buyCriteria(int student, int index) {
    auto &criterion = criteria[index];
    if (criterion->getOwner() != nullptr) {
        throw AlreadyOwnedException("Criterion is already owned!");
    }
    if (students[student]->hasResources({ResourceType::CAFFEINE, ResourceType::LAB,
                                         ResourceType::LECTURE, ResourceType::TUTORIAL})) {
        criterion->setOwner(students[student].get());
        students[student]->addCriteria(index);
        students[student]->removeResources({ResourceType::CAFFEINE, ResourceType::LAB,
                                            ResourceType::LECTURE, ResourceType::TUTORIAL});
        cout << "Criterion " << index << " acquired by student " << student << endl;
    } else {
        throw InsufficientResourcesException("Not enough resources to buy criterion!");
    }
}

void Board::improveCriteria(int student, int index) {
    auto &criterion = criteria[index];
    if (criterion->getOwner() != students[student].get()) {
        throw InvalidCriterionImprovementException("Criterion is not owned by this student!");
    }
    if (criterion->getUpgradeLevel() == UpgradeLevel::EXAM) {
        throw InvalidCriterionImprovementException("Criterion is already fully upgraded!");
    }
    vector<ResourceType> cost;
    if (criterion->getUpgradeLevel() == UpgradeLevel::ASSIGNMENT) {
        cost = {ResourceType::LECTURE, ResourceType::LECTURE, ResourceType::STUDY, ResourceType::STUDY, ResourceType::STUDY};
    } else if (criterion->getUpgradeLevel() == UpgradeLevel::MIDTERM) {
        cost = {ResourceType::CAFFEINE, ResourceType::CAFFEINE, ResourceType::CAFFEINE,
                ResourceType::LAB, ResourceType::LAB, ResourceType::LECTURE,
                ResourceType::LECTURE, ResourceType::TUTORIAL, ResourceType::STUDY, ResourceType::STUDY};
    }
    if (students[student]->hasResources(cost)) {
        criterion->improveCriteria();
        students[student]->removeResources(cost);
        cout << "Criterion " << index << " improved by student " << student << endl;
    } else {
        throw InsufficientResourcesException("Not enough resources to improve criterion!");
    }
}

void Board::moveGeese(int index) {
    if (index == geesePosition) {
        throw InvalidGeesePlacementException("Geese are already on this tile!");
    }
    geesePosition = index;
    cout << "Geese moved to tile " << index << endl;
}

void Board::trade(int offeringStudent, int receivingStudent, ResourceType offered, ResourceType requested) {
    if (students[offeringStudent]->getResourceCount(offered) == 0) {
        throw InsufficientResourcesException("Offering student does not have the resource to trade!");
    }
    if (students[receivingStudent]->getResourceCount(requested) == 0) {
        throw InsufficientResourcesException("Receiving student does not have the requested resource!");
    }
    students[offeringStudent]->removeResource(offered);
    students[offeringStudent]->addResource(requested);
    students[receivingStudent]->removeResource(requested);
    students[receivingStudent]->addResource(offered);
    cout << "Trade successful!" << endl;
}