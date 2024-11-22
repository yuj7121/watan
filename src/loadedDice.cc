#include <iostream>
#include "loadedDice.h"

using namespace std; 

class LoadedDice : public Dice { 
    LoadedDice(int rollValue) : rollValue{rollValue} {}

    ~LoadedDice() {}

    int roll() {
        return rollValue;
    }
};