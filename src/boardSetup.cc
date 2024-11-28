#include "boardSetup.h"

BoardSetup::BoardSetup() {}

void BoardSetup::setup(std::shared_ptr<Board> b) {
    setupResources();

    //create goals
    for(int i = 0; i < NUM_GOALS; ++i) {
        std::shared_ptr<Goal> curr {new Goal(i, nullptr)};
        b->goals.emplace_back(curr);
    }
    
    //create criterions
    for(int i = 0; i < NUM_CRITERION; ++i) {
        //create the criteria
        std::vector<std::shared_ptr<Goal>> adj;
        for(auto it = (ADJ_GOAL_PER_CRITERIA.at(i)).begin(); it != (ADJ_GOAL_PER_CRITERIA.at(i)).end(); ++it) {
            adj.emplace_back((b->goals).at(*it));
        }
        std::shared_ptr<Criteria> curr {new Criteria(i, CompletionType::NONE, adj, nullptr)};
        b->criterion.emplace_back(curr);
    }

    //attatch adjacent criterions to each goal
    for(int i = 0; i < NUM_GOALS; ++i) {
        for(auto it = (ADJ_GOAL_PER_CRITERIA.at(i)).begin(); it != (ADJ_GOAL_PER_CRITERIA.at(i)).end(); ++it) {
            (b->goals.at(i))->attachCriteria((b->criterion).at(*it));
        }
    }

    //create tiles
    for (int i = 0; i < NUM_TILES; i++) {
        ResourceType currType;
        if(resourceTypes[i] < 0 || resourceTypes[i] > 5) {
            throw ResourceTypeConversionException("Invalid resource type index!");
        } else {
            currType = intToResourceType(resourceTypes[i]);
        }
        //figure out surrounding criteria
        
        //figure out surrounding goals


        std::shared_ptr<Tile> curr = std::make_shared<Tile>(i, resourceValues[i], currType, false);
        b->tiles.emplace_back(curr);
    }

}

