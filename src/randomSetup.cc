#include "randomSetup.h"

RandomSetup::RandomSetup(int seed) : seed{seed} {
    rng.seed(seed);
}

void RandomSetup::setup() {
/* TODO: figure out which one to use -> how to apply seed?
    array<pair<int, int>, 19> tiles;
	array<int, 6> availableResources{ {3, 3, 4, 4, 4, 1} };
	array<int, 12> availableValues{ {0, 1, 2, 2, 2, 2, 0, 2, 2, 2, 2, 1} };

    for (int i = 0; i < 19; ++i) {
        uniform_int_distribution<int> rDistribution(0, 5);
        int randomResource = rDistribution(eng); 
        while (availableResources.at(randomResource) == 0) {
            randomResource = rDistribution(eng); 
        }
        --availableResources.at(randomResource); 
        int randomValue = 0; 
        if (randomResource = 5) {
            randomValue = 7; // NETFLIX resource 
        } else { 
            uniform_int_distribution<int> vDistribution(1, 12); 
            randomValue = vDistribution(eng); 
            while (availableValues.at(randomValue - 1) == 0) {
                randomValue = rDistribution(eng); 
            }
            --availableValues.at(randomValue - 1); 
        }
        pair<int, int> thisTile{randomResource, randomValue}; 
        tiles.at(i) = thisTile; 
    }
*/
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

