#include "boardSetup.h"

BoardSetup::BoardSetup() {}

void BoardSetup::setup(shared_ptr<Board> b){
    setupResources();
    for(int i = 0; i < NUM_TILES; i++) {
        string currType;
        switch (resourceTypes[i]) {
            case 0:
            currType = "CAFFEINE";
            break;
            case 1:
            currType = "LAB";
            break;
            case 2:
            currType = "LECTURE";
            break;
            case 3:
            currType = "STUDY";
            break;
            case 4:
            currType = "TUTORIAL";
            break;
            case 5:
            currType = "NETFLIX";
            break;
        }        
        shared_ptr<Tile> curr {new Tile(i, resourceValues[i], currType, false)};
        b->tiles.emplace_back(curr);
    }

    //TODO: create goals

    //TODO: create criterions

}

