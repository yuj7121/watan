#ifndef LOADEDDICE_H
#define LOADEDDICE_H

#include <iostream>
#include <random>
#include "dice.h"

using namespace std; 

class LoadedDice : public Dice { 
        int rollValue = 0; 
    public: 
        LoadedDice(int rollValue); 
        int roll() override; 
};

#endif

