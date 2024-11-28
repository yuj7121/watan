#include "board.h"

using namespace std;

Board::Board() : geesePosition(NOT_IN_PLAY) {}

const std::vector<std::shared_ptr<Tile>>& Board::getTiles() const {
    return tiles;
}

int Board::getGeese() const { return geesePosition; }

// EFFECTS: Distributes resources to students based on the rolled number.
void Board::tileRolled(const int roll) {
    for (unsigned int i = 0; i < tiles.size(); i++) {
        const auto &tile = tiles[i];
        if (tile->getValue() == roll && tile->getResourceType() != ResourceType::NETFLIX) {
            const auto &criteriaIndices = CRITERION_PER_TILE[i];
            for (int criterionIndex : criteriaIndices) {
                const auto &crit = criterion[criterionIndex];
                if (crit->getOwner()) {
                    crit->getOwner()->addResource(tile->getResourceType());
                }
            }
        }
    }
}

bool Board::tileHasStudent(int tileIndex, Student* student) {
    return (tiles.at(tileIndex))->studentOwns(student);
}


// EFFECTS: Attempts to buy a goal at the specified index for the student.
//          Updates the goal's owner, student's goals, and deducts the cost
//          if successful.
void Board::buyGoal(Student* student, const int index) {
    auto &goal = goals[index];
    if (goal->getOwner() != nullptr) {
        throw AlreadyOwnedException("Goal is already owned!");
    }
    if (student->hasResources({ResourceType::STUDY, ResourceType::TUTORIAL})) {
        student->playGoal(goals.at(index));
        student->removeResources({ResourceType::STUDY, ResourceType::TUTORIAL});
    } else {
        throw InsufficientResourcesException("Not enough resources to buy goal!");
    }
}

// EFFECTS: Attempts to buy a criteria at the specified index for the student.
//          Updates the critera's owner, student's criterion, and deducts the cost
//          if successful.
void Board::buyCriteria(Student* student, const int index) {
    auto &crit = criterion[index];
    // TODO: if its the start of the game, don't need to check resources
    if (crit->getOwner() != nullptr) {
        throw AlreadyOwnedException("Criterion is already owned!");
    }
    if (student->hasResources({ResourceType::CAFFEINE, ResourceType::LAB,
                                         ResourceType::LECTURE, ResourceType::TUTORIAL})) {
        student->playCriteria(criterion.at(index), false);
        student->removeResources({ResourceType::CAFFEINE, ResourceType::LAB,
                                            ResourceType::LECTURE, ResourceType::TUTORIAL});
    } else {
        throw InsufficientResourcesException("Not enough resources to buy criterion!");
    }
}

// EFFECTS: Attempts to improve a criterion at the specified index for the student.
//          Updates the criterion's level and deducts the cost if successful.
void Board::improveCriteria(Student* student, const int index) {
    auto &crit = criterion[index];
    if (crit->getOwner() != student) {
        throw InvalidCriterionImprovementException("Criterion is not owned by this student!");
    }
    if (crit->getCompletionLevel() == 3) { //exam
        throw InvalidCriterionImprovementException("Criterion is already fully upgraded!");
    }
    vector<ResourceType> cost;
    if (crit->getCompletionLevel() == 1) { //asisngment
        cost = {ResourceType::LECTURE, ResourceType::LECTURE, ResourceType::STUDY, ResourceType::STUDY, ResourceType::STUDY};
    } else if (crit->getCompletionLevel() == 2 ) { //midterm
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

// EFFECTS: this->geesePosition becomes the parameter index.
void Board::moveGeese(const int index) {
    if (index == geesePosition) {
        throw InvalidGeesePlacementException("Geese are already on this tile!");
    }
    geesePosition = index;
}

// EFFECTS: offeringStudent gets +1 requested ResourceType, -1 offered ResourceType.
//          receivingStudent gets +1 offered ResourceType, -1 requested ResourceType.
void Board::trade(Student* offeringStudent, Student* receivingStudent,
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

string Board::save() { 
    string output; 
    for (auto &t : tiles) { 
        output += t->save() + " "; 
    } 
    ostringstream goose; 
    goose << geesePosition; 
    output += '\n'; 
    output += goose.str();

    return output; 
}