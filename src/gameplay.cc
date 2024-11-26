#include "gameplay.h"

using namespace std; 

Gameplay::Gameplay() {}

void Gameplay::newGame() {
    vector<pair<int, int>> tiles(19); 
	vector<int> availableResources = {3, 3, 4, 4, 4, 1};
	vector<int> availableValues = {0, 1, 2, 2, 2, 2, 0, 2, 2, 2, 2, 1};

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
    // TODO: transfer this information to the board/text display
}

void Gameplay::loadGame(const std::string file) { 
    ifstream f{file};
	int curTurn;
    // TODO: check types 
    vector<vector<int>> studentResources(4, vector<int>(5));
    vector<vector<int>> studentGoals(4);
    vector<vector<pair<int, int>>> studentCriteria(4);
	int geese;

    for (int i = 0; i < 7; ++i) {
        string line; 
        getline(f, line); 

        istringstream iss{line}; 
        int input; 
        while (iss >> input) {
            // curTurn
            if (i == 0) {
                curTurn = input; 
            // studentData
            } else if (i >= 1 && i <= 4) {
                int playerIndex = i - 4; 
                vector<int> resources(5); 
                for (int j = 0; j < 5; ++j) {
                    resources.at(j) = input; 
                    iss >> input; 
                }
                studentResources.at(playerIndex) = resources; 

                if (input == static_cast<int>('g')) iss >> input; 

                // goals
                vector<int> goals; 
                while (input != static_cast<int>('c')) {
                    goals.emplace_back(input); 
                    iss >> input; 
                }
                studentGoals.at(playerIndex) = goals; 

                if (input == static_cast<int>('c')) iss >> input; 

                // criteria
                vector<pair<int, int>> criteria; 
                while (iss >> input) {
                    int level; 
                    iss >> level; 
                    criteria.emplace_back(input, level); 
                }
                studentCriteria.at(playerIndex) = criteria; 
            // board 
            } else if (i == 5) {
                setup = std::make_unique<FileSetup>(file); 
                setup->setup(); 
            } else {
                geese = input; 
            }
        }
    }

    // TODO: text display and board display
}

void Gameplay::loadBoard(const std::string file) {
    setup = std::make_unique<FileSetup>(file); 
    setup->setup(); 

    // TODO: text display and board display 
}

void Gameplay::rollDice(int val = -1, bool isFairDice = false) {
    int roll; 
    if (isFairDice) {
        dice = std::make_unique<FairDice>(eng); 
        roll = dice->roll(); 
    } else {
        dice = std::make_unique<LoadedDice>(val); 
        roll = dice->roll(); 
    }

    if (roll == 7) {
        // TODO: GEESE
    }
}

string Gameplay::curTurn() const { 
    if (whoseTurn == 0) return "Blue";
    else if (whoseTurn == 1) return "Red";
    else if (whoseTurn == 2) return "Orange";
    else if (whoseTurn == 3) return "Yellow";
    else return "";
}

bool Gameplay::gameOver() const { 
    for (int i = 0; i < 4; ++i) {
        if (Students[i]->getVictoryPoints() >= 10) {
            winnerIndex = i;
            return true;
	    }
    }   
}

void Gameplay::board() const { 
    cout << *textDisplay << endl;	
}

void Gameplay::help() const {
    cout << "Valid commands:" << endl
        << "board" << endl
        << "status" << endl
        << "criteria" << endl
        << "achieve <goal>" << endl
        << "complete <criterion>" << endl
        << "improve <criterion>" << endl
        << "trade <colour> <give> <take>" << endl
        << "next" << endl
        << "save <file>" << endl
        << "help" << endl;
}



void Gameplay::

