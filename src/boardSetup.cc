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

    //create goals
    for(int i = 0; i < NUM_GOALS; ++i) {
        std::shared_ptr<Goal> curr {new Goal(i, nullptr)};
        b->goals.emplace_back(curr);
    }
    
    //create criterions
    for(int i = 0; i < NUM_CRITERION; ++i) {
        //create the criteria
        std::vector<std::shared_ptr<Goal>> adj;
        for(auto it = (adjGoalPerCriteria.at(i)).begin(); it != (adjGoalPerCriteria.at(i)).end(); ++it) {
            adj.emplace_back((b->goals).at(*it));
        }
        std::shared_ptr<Criteria> curr {new Criteria(i, CompletionType::NONE, adj, nullptr)};
        b->criterion.emplace_back(curr);
    }
    

    //attatch adjacent criterions to each goal
    for(int i = 0; i < NUM_GOALS; ++i) {
        for(auto it = (adjGoalPerCriteria.at(i)).begin(); it != (adjGoalPerCriteria.at(i)).end(); ++it) {
            (b->goals.at(i))->attachCriteria((b->criterion).at(*it));
        }
    }

}

