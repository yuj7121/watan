#include "gameplay.h"


using namespace std; 

Gameplay::Gameplay() : theBoard{std::make_shared<Board>()} {}

void Gameplay::newGame(int seed) {
    setup = std::make_unique<RandomSetup>(seed);
    setup->setup(theBoard); 
    // TODO: text display and board display
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
                setup->setup(theBoard); 
            } else {
                geese = input; 
            }
        }
    }

    // TODO: text display and board display
}

void Gameplay::loadBoard(const std::string file) {
    setup = std::make_unique<FileSetup>(file); 
    setup->setup(theBoard); 
    // TODO: text display and board display 
}

loseToGeese(unique_ptr<Student> student) {
    int numResources;
    //find the total number of resources
    for(int i = 0; i < NUM_RESOURCE_TYPES; ++i) {
        ResourceType::ResourceType type;
        switch(i){
            case 0:
                type = ResourceType::CAFFEINE;
                break;
            case 1:
                type = ResourceType::LAB;
                break;
            case 2:
                type = ResourceType::LECTURE;
                break;
            case 3:
                type = ResourceType::STUDY;
                break;
            case 4:
                type = ResourceType::TUTORIAL;
                break;
            case 5:
                type = ResourceType::NETFLIX;
                break;
        } //end of switch block
        numResources += student.getResource(type);
    }

    //output
    cout << "Student"
    << COLOUR_TO_STRING.at(students[j]->getColour())
    << " loses " << numResources << "resources to the geese. They lose:" << endl;

    //make student lose resources
    vector<bool> toLose;
    for(int i = 0; i < numResources; ++i) {
        if(i < numResources / 2){
            toLose.emplace_back(true);
        } else {
            toLose.emplace_back(false);
        }
    }
    std::random_shuffle(toLose.begin(), toLose.end());

    for(int i = 0; i < NUM_RESOURCE_TYPES; ++i) {
        
    }

}
void Gameplay::rollDice(int val, bool type) {
    int roll; 
    if (type) { // fair dice
        dice = std::make_unique<FairDice>(eng); 
        roll = dice->roll(); 
    } else { // loaded dice 
        dice = std::make_unique<LoadedDice>(val); 
        roll = dice->roll(); 
    }

    if (roll == 7) {
        // TODO: GEESE

    } else {
        theBoard.tileRolled(roll);
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
        if (Students[i]->getVictoryPoints() == 10) {
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


void Gameplay::initialAssignments() {
    for(int i = 0; i < 2; ++i) {
        int start, end;
        if(i == 0) {
            start = 0;
            end = NUM_STUDENTS;
        } else {
            start = NUM_STUDENTS - 1;
            end = 0;            
        }
        while(j < NUM_STUDENTS && j >= 0;) {
            bool validInput = false;
            do {
                try {
                    int input;
                    cout << "Student " 
                    << COLOUR_TO_STRING.at(students[j]->getColour());
                    << ", where do you want to complete an Assignment?" << endl;
                    if (!(cin >> input)) {
                        throw new InvalidInputException("not an integer, try again.");
                    } else {
                        validInput = true;
                        theBoard.buyCriteria(students[j], input);
                    }
                } catch (InvalidInputException& e) {
                    cerr << e.what() << endl;
                } //end of try catch block
            } while (!validInput); //end of inner while

            //increase or decrease j depending on if it's the first round or the second
            if(i == 0) {
                ++j;
            } else {
                --j;
            }
        } //end of outer while loop
    } //end of outer for
}//end of fucntion


void Gameplay::beginTurn(unique_ptr<Student> student) {
    cout << "Student " << COLOUR_TO_STRING.at(student->getColour()) << "'s turn." << endl;
    cout << student;

    string input;
    do {
        try{
            //if user wants loaded
            if(input == "load") {
                int invalid = true;
                cout << "Input a roll between 2 and 12:" << endl;
                int val;
                while (invalid) {
                    try {
                        if(!(cin >> val)) {
                            throw new InvalidInputException("not an integer");
                        } else {
                            if(val < 2 || val > 12) {
                                throw new OutOfRangeInputException(val);
                            } else {
                                invalid = false;
                            }
                        } //end of if else block
                    } catch (InvalidInputException& e) { // not an int
                        cerr << e.what() << endl;
                    } catch (OutOfRangeInputException& e) { //int out of range
                        cerr << e.what() << endl;
                    } //end of try catch
                } //end of while
                rollDice(, true);
                //if user wants fair            
            } else if (input == "fair") {
                rollDice(-1, true);
            } else {
                throw new InvalidInputException(input);
            }
        } catch (InvalidInputException& e) { //invalid input for what to do
            cerr << e.what() << endl;
        } //end of try catch
    } while (input != "roll"); //end of while loop

}//end of function



