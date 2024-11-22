#include <iostream> 
#include <vector>
#include <memory>
#include <string>
#include "criterion.h"

using namespace std; 

Criteria::Criteria(int index) : index{index}, level{CompletionType::NONE}, owner{nullptr} {}

int Criteria::getIndex() const { return index; } 

CompletionType Criteria::getCompletionType() const { return level; }

// string Criteria::getOwner() const { return

bool Criteria::isOwnedBy(Student* player) const {
    return owner==player;
}

bool isAdjacent(); 

void Criteria::setOwner(Student* player) {
    owner = player; 
} 

void improve(Student* player) {

}

