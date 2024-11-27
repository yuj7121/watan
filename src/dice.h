#ifndef DICE_H
#define DICE_H
// DICE.H: A Factory that returns an int from two dice.

#include <memory>
#include <iostream> 
using namespace std; 

class Dice { 
    public: 
        virtual int roll() = 0; 
        virtual ~Dice() = default;
};

#endif
