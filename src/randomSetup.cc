#include "randomSetup.h"

RandomSetup::RandomSetup(int seed) : seed{seed} {
    rng.seed(seed);
}

void RandomSetup::setupResources() {
    vector<int> tilesTypes{0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5};
    vector<int> tilesValues{2, 12, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11};
    int netflixDone = 0;

    std::shuffle(tilesTypes.begin(), tilesTypes.end(), rng);
    std::shuffle(tilesValues.begin(), tilesValues.end(), rng);

    //set up the resource types and values for each tile
    for(int i = 0; i < NUM_TILES; ++i){
        resourceTypes[i] = tilesTypes.at(i);
        if(tilesTypes.at(i) == 5){
            netflixDone = 1;
        }
        resourceValues[i] = tilesValues.at(i + netflixDone);
    }
}

