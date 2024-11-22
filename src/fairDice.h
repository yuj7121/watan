#ifndef _FAIR_DICE_H_
#define _FAIR_DICE_H_

#include <iostream>
#include <algorithm> 
#include "dice.h"

using namespace std; 

class FairDice : public Dice {
    // Fields
    public: 
        FairDice();
        int roll() override; 
        virtual ~FairDice(); 
}; 

#endif