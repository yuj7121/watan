#ifndef FAIRDICE_H_
#define FAIRDICE_H_

#include <iostream>
#include <random>
#include <algorithm>
#include <memory>
#include "dice.h"

using namespace std; 

class FairDice : public Dice {
    std::shared_ptr<default_random_engine> generator;
public: 
    FairDice(std::shared_ptr<default_random_engine> generator);
    int roll() override; 
}; 

#endif
