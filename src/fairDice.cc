#include <iostream>
#include <algorithm> 
#include "fairDice.h"

using namespace std; 

FairDice::FairDice(default_random_engine *generator) : generator{generator} {}

int FairDice::roll() {
    uniform_int_distribution<int> distribution(1,6);
    return dist(*eng) + dist(*eng);
}