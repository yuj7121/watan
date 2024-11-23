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
    
    //TODO: ACC IMPLEMENT SOME WAY TO FIGURE OUT ADJACENCY
    int tileAdjGoals[NUM_TILES][6];
    int tileAdjCriterions[NUM_TILES][6];
    int goalsAdjCriteria[NUM_GOALS][3];
    int criterionAdjgoals[NUM_CRITERION][3];
    for(int i = 0; i < NUM_TILES; ++i) {
        int g0, g1, g2, g3, g4, g5 = -1;
        int c0, c1, c2, c3, c4, c5 = -1;
        int row;
        if(i == 0) {
            row = 0;
        } else if (i == 1 || i == 1) {
            row = 1;
        } else if(i == 16 || i = 17) {
            row = 8;
        } else if(i == 18) {
            row = 9;
        } else if(i ==)

        c0 = factor;
        c1 = c0 + 1;
        c2 = lfksdjf;
        c3 = c3 + 1;
        c4 = dfsld;
        c5 = c4 + 1;
    }

    //create goals
    for(int i = 0; i < NUM_GOALS) {
        shared_ptr<Goal> curr {new Goal(i, nullptr)};
        b->goals.emplace_back(curr);
    }
    
    //create criterions
    for(int i = 0; i < NUM_CRITERION) {
        int goal1;
        int goal2;
        int goal3;
        vector<shared_ptr<Goal>> adjGoals;

        //calculate the index of adjacent goals
        for(int i = 0; i < NUM_CRITERION)
        

        //make a vector out of those

        //create the criteria
        shared_ptr<Criteria> curr {new Criteria(i, CompletionType::NONE, adjGoals, nullptr)};
        b->criterion.emplace_back(curr);
    }
    

    //attatch adjacent criterions to each goal
    for(int i = 0; i < NUM_GOALS) {
        int j;
        (b->goals.at(i))->attachCriteria(fjdslkfjadsl;fj);
    }

}

