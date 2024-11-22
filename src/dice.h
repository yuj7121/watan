#ifndef DICE_H
#define DICE_H

#include <iostream> 

class Dice { 
    public: 
        virtual int roll() = 0; 
        virtual ~Dice() = default;
};

#endif
