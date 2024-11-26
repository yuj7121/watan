#include "fairDice.h"

FairDice::FairDice(unique_ptr<default_random_engine> generator)
    : generator(generator) {}

int FairDice::roll() {
    uniform_int_distribution<int> distribution(1, 6);
    return distribution(*generator) + distribution(*generator);
}
