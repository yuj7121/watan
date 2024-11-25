#include <iostream>
#include <vector>

#include "constants.h"
#include "tile.h"
#include "criterion.h"
#include "goal.h"

using namespace std; 


Board::Board() : geesePosition(NOT_IN_PLAY) {}

void Board::printBoard() const {

}

const std::vector<std::shared_ptr<Tile>>& Board::getTiles() const {

}

int Board::getGeese() const {

}

void Board::tileRolled(int roll) {

}

void Board::buyGoal(int student, int index){

}


void Board::buyCriteria(int student, int index){

}

void Board::improveCriteria(int student, int index) {

}

void Board::moveGeese(int index) {

}

void Board::trade(int offeringStudent, int receivingStudent, ResourceType type) {

}