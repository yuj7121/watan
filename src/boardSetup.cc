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
    //make sure they're in clockwise order starting from top left(or top)
    int tileAdjGoals[NUM_TILES][6];
    int tileAdjCriterions[NUM_TILES][6];

    tileAdjGoals = {{0,2,7,10,6,1}, //tile 0
    {3,6,14,18,13,5}, {4,8,16,19,15,7}, //tiles 1 and 2
    {9,13,21,26,20,12}, {10,15,23,27,22,14}, {11,17,25,28,24,16}, //tiles 3,4,5
    {18,22,31,35,30,21}, {19,24,33,36,32,23}, //tiles 6 and 7
    {26,30,38,43,37,29}, {27,32,40,44,39,31}, {28,34,42,45,41,33} //tiles 8,9,10
    {35,39,48,52,47,38}, {36,41,50,53,49,40} //tiles 11 and 12
    {43,47,55,60,54,46}, {44,49,57,61,56,48}, {45,51,59,62,58,50}, //tiles 13,14,15
    {52,56,64,67,63,55}, {53,58,66,68,65,57}, //tiles 16 and 17
    {61,65,70,71,69,64}}; //tile 18

    std::set<int> goalsAdjGoals[NUMGOALS] 
    std::set<int> goalsAdjCriterion[NUM_GOALS];
    std::set<int> criterionAdjGoals[NUM_CRITERION];
    std::set<int> criterionAdjCriterion[NUM_CRITERION];

    //for each tile, go thru goals/criterion and add adjacency
    for(int i = 0; i < NUM_TILES) {
        for(int j = 0; i < 6; ++j) {
            int currGoal = tileAdjGoals[i][j];
            int currCriteria = tileAdjCriterions[i][j];

            //for goals
            if(j == 0){
                goalsAdjGoals[currGoal].insert(tileAdjGoals[i][5]);
                goalsAdjGoals[currGoal].insert(tileAdjGoals[i][j + 1]);
                goalsAdjCriterion[currGoal].insert(tileAdjCriterions[i][j]);
                goalsAdjCriterion[currGoal].insert(tileAdjCriterions[i][j + 1]);
            } else if (j == 5) {
                goalsAdjGoals[currGoal].insert(tileAdjGoals[i][j - 1]);
                goalsAdjGoals[currGoal].insert(tileAdjGoals[i][0]);
                goalsAdjCriterion[currGoal].insert(tileAdjCriterions[i][j]);
                goalsAdjCriterion[currGoal].insert(tileAdjCriterions[i][0]);
            } else {
                goalsAdjGoals[currGoal].insert(tileAdjGoals[i][j - 1]);
                goalsAdjGoals[currGoal].insert(tileAdjGoals[i][j + 1]);
                goalsAdjCriterion[currGoal].insert(tileAdjCriterions[i][j]);
                goalsAdjCriterion[currGoal].insert(tileAdjCriterions[i][j + 1]);
            }
            //for criteria
            if(j == 0) {
                criterionAdjGoals[currCriteria].insert(tileAdjGoals[i][5]);
                criterionAdjGoals[currCriteria].insert(tileAdjGoals[i][j]);
                criterionAdjCriterion[currCriteria].insert(tileAdjCriterions[i][5]);
                criterionAdjCriterion[currCriteria].insert(tileAdjCriterions[i][j + 1]);
            } else if (j == 5) {
                criterionAdjGoals[currCriteria].insert(tileAdjGoals[i][j - 1]);
                criterionAdjGoals[currCriteria].insert(tileAdjGoals[i][j]);
                criterionAdjCriterion[currCriteria].insert(tileAdjCriterions[i][j - 1]);
                criterionAdjCriterion[currCriteria].insert(tileAdjCriterions[i][0]);
            } else {
                criterionAdjGoals[currCriteria].insert(tileAdjGoals[i][j - 1]);
                criterionAdjGoals[currCriteria].insert(tileAdjGoals[i][j]);
                criterionAdjCriterion[currCriteria].insert(tileAdjCriterions[i][j - 1]);
                criterionAdjCriterion[currCriteria].insert(tileAdjCriterions[i][j + 1]);
            }
        }
    }

    //create goals
    for(int i = 0; i < NUM_GOALS) {
        shared_ptr<Goal> curr {new Goal(i, nullptr)};
        b->goals.emplace_back(curr);
    }
    
    //create criterions
    for(int i = 0; i < NUM_CRITERION) {
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

