#include "fairDice.h"
using namespace std; 

FairDice::FairDice(std::shared_ptr<default_random_engine> generator)
    : generator{generator} {}

int FairDice::roll() {
    uniform_int_distribution<> dist(1, 6);
    return dist(*generator) + dist(*generator);
}


