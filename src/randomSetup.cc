#include "randomSetup.h"

RandomSetup::RandomSetup(int seed) : seed{seed} {}

void RandomSetup::setupResources() {
    int typeMin = 0;
    int typeMax = 5;
    int valMin = 1;
    int valMax = 12;

    int random;
    
    //set up the resource types and values for each tile
    for(int i = 0; i < NUM_TILES; ++i){
        random = typeMin + (std::rand() % (typeMax - typeMin + 1));
        resourceTypes[i] = random;
        random = valMin + (std::rand() % (valMax - valMin + 1));
        resourceValues[i] = random;
    }
}

