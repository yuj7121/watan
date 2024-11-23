#ifndef _FAIRDICE_H_
#define _FAIRDICE_H_

#include <iostream>
#include <random> 
#include "dice.h"

using namespace std; 

class FairDice : public Dice {
    default_random_engine *generator;
public: 
    FairDice(default_random_engine *generator);
    int roll() override; 
}; 

#endif