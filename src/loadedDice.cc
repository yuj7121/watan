#include "loadedDice.h"

using namespace std; 

LoadedDice::LoadedDice(int rollValue) : rollValue{rollValue} {}

int LoadedDice::roll() {
    return rollValue;
}
