#include <iostream> 
#include <vector> 
#include <string>

#include "goal.h"
#include "criteria.h"
#include "player.h"

using namespace std; 

Goal::Goal(int index) : index{index}, owner{nullptr} {}

int getIndex() const { return index; }

Student getOwner() const { return owner; }

void buildGoal(Student *player); 

bool isOwnedBy(Student *player) const { return owner==player; }