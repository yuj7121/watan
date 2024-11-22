#include <iostream>
#include <algorithm> 
#include "fairDice.h"

using namespace std; 

class FairDice : public Dice {
    virtual int roll() = 0; 
}; 