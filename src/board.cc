#include "board.h"

using namespace std;

Board::Board() : geesePosition(NOT_IN_PLAY) {}

std::vector<std::shared_ptr<Tile>> Board::getTiles() const {
    return tiles;
}

vector<shared_ptr<Criteria>> Board::getCriteria() const {
    return criteria; 
}
vector<shared_ptr<Goal>> Board::getGoals() const {
    return goals; 
}

int Board::getGeese() const { return geesePosition; }

// EFFECTS: Distributes resources to students based on the rolled number.
void Board::tileRolled(const int roll) {
    int gained[NUM_STUDENTS][NUM_RESOURCE_TYPES] = {0};
    //go thru each tile, chekc if it has the value
    for (unsigned int i = 0; i < NUM_TILES; i++) {
        const auto &tile = tiles[i];
        //if this tile has the valeu same as the dice roll
        if (tile->getValue() == roll && tile->getResourceType() != ResourceType::NETFLIX) {
            const auto &criteriaIndices = CRITERION_PER_TILE[i];
            //for each criteria that's part of that tile
            for (int criteriaIndex : criteriaIndices) {
                const auto &crit = criteria[criteriaIndex];
                if (crit->getOwner()) {
                    crit->getOwner()->addResource(tile->getResourceType());
                    gained[crit->getOwner()->getIndex()][resourceTypeToInt(tile->getResourceType())] += 1;
                }
            }
        }
    }
    for(int i = 0; i < NUM_STUDENTS; ++i) {
        bool gainedNothing = true;
        for(int j = 0; j < NUM_RESOURCE_TYPES; ++j) { 
            int gainedNum = gained[i][j];
            if(gainedNum != 0){
                if(gainedNothing){
                    gainedNothing = false;
                    cout << "Student " << colourToString(intToColour(i)) << " gained:" << endl;
                }
                cout << gainedNum << " " << resourceTypeToString(intToResourceType(j)) << endl;
            }
        }
    }
}

// EFFECTS: Attempts to buy a goal at the specified index for the student.
//          Updates the goal's owner, student's goals, and deducts the cost
//          if successful.
void Board::buyGoal(shared_ptr<Student> student, const int index) {
    auto &goal = goals[index];
    if (goal->getOwner() != nullptr) {
        throw AlreadyOwnedException("Goal is already owned!\n");
    }
    if (student->hasResources({ResourceType::STUDY, ResourceType::TUTORIAL})) {
        student->playGoal(goals.at(index));
        student->removeResources({ResourceType::STUDY, ResourceType::TUTORIAL});
    } else {
        throw InsufficientResourcesException("Not enough resources to buy goal!\n");
    }
}

void Board::sogBuyCriteria(shared_ptr<Student> student, const int index) {
    auto &crit = criteria[index];
    if (crit->getOwner() != nullptr) {
        throw AlreadyOwnedException("Criteria is already owned!\n");
    }
    if (!(student->playCriteria(criteria.at(index), true))) {
        throw AdjacentPlacementException("There is an adjacent criterion already owned!\n"); 
    }
}

// EFFECTS: Attempts to buy a criteria at the specified index for the student.
//          Updates the critera's owner, student's criteria, and deducts the cost
//          if successful.
void Board::buyCriteria(shared_ptr<Student> student, const int index) {
    auto &crit = criteria[index];
    if (crit->getOwner() != nullptr) {
        throw AlreadyOwnedException("Criteria is already owned!\n");
    }
    if (student->hasResources({ResourceType::CAFFEINE, ResourceType::LAB,
                                         ResourceType::LECTURE, ResourceType::TUTORIAL})) {
        if (!(student->playCriteria(criteria.at(index), false))) {
            throw AdjacentPlacementException("There is an adjacent criterion already owned!\n"); 
        }
        student->removeResources({ResourceType::CAFFEINE, ResourceType::LAB,
                                            ResourceType::LECTURE, ResourceType::TUTORIAL});
    } else {
        throw InsufficientResourcesException("Not enough resources to buy criteria!\n");
    }
}

// EFFECTS: Attempts to improve a criteria at the specified index for the student.
//          Updates the criteria's level and deducts the cost if successful.
void Board::improveCriteria(shared_ptr<Student> student, const int index) {
    auto &crit = criteria[index];
    if (crit->getOwner() != student.get()) {
        throw InvalidCriteriaImprovementException("Criteria is not owned by this student!\n");
    }
    if (crit->getCompletionLevel() == 3) {
        throw InvalidCriteriaImprovementException("Criteria is already fully upgraded!\n");
    }
    vector<ResourceType> cost;
    if (crit->getCompletionLevel() == 1) {
        cost = {ResourceType::LECTURE, ResourceType::LECTURE, ResourceType::STUDY, ResourceType::STUDY, ResourceType::STUDY};
    } else if (crit->getCompletionLevel() == 2) {
        cost = {ResourceType::CAFFEINE, ResourceType::CAFFEINE, ResourceType::CAFFEINE,
                ResourceType::LAB, ResourceType::LAB, ResourceType::LECTURE,
                ResourceType::LECTURE, ResourceType::TUTORIAL, ResourceType::STUDY, ResourceType::STUDY};
    }
    if (student->hasResources(cost)) {
        student->playCriteria(crit, false);
        // crit->playCriteria(student, false);
        student->removeResources(cost);
    } else {
        throw InsufficientResourcesException("Not enough resources to improve criteria!\n");
    }
}

// EFFECTS: this->geesePosition becomes the parameter index.
void Board::moveGeese(const int index) {
    if (index == geesePosition) {
        throw InvalidGeesePlacementException("Geese are already on this tile!\n");
    }
    geesePosition = index;
}

// EFFECTS: offeringStudent gets +1 requested ResourceType, -1 offered ResourceType.
//          receivingStudent gets +1 offered ResourceType, -1 requested ResourceType.


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

bool Board::tileHasStudent(int tileIndex, shared_ptr<Student> student) {
    // TODO: replace the following dummy impl.
    return tiles.at(tileIndex)->studentOwns(student);
}
