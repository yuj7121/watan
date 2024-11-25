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
    int tileAdjGoals[NUM_TILES][6] = 
    int tileAdjCriterions[NUM_TILES][6] = {{0,1,3,4,8,9},{2,3,7,8,13,14},{4,5,9,10,15,16},
    {6,7,12,13,18,19},{8,9,14,15,20,21},{10,11,16,17,22,23},{13,14,19,20,25,26},{15,16,21,22,27,28},
    {18,19,24,25,30,31},{20,21,26,27,32,33},{22,23,28,29,34,35},{25,26,31,32,37,38},{27,28,33,34,39,40},
    {20,31,36,37,42,43},{32,33,38,39,44,45},{34,35,40,41,46,47},{37,38,43,44,48,49},{39,40,45,46,50,51},
    {44,45,49,50,52,53}};
    int goalsAdjCriteria[NUM_GOALS][3];
    int criterionAdjgoals[NUM_CRITERION][3];
    

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

