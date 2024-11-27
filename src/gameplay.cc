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

void Gameplay::loseToGeese(unique_ptr<Student> student) {
    int numResources; //total number of resources the student has
    //find the total number of resources
    for(auto it = RESOURCE_TYPE_STRINGS.begin(); it != RESOURCE_TYPE_STRINGS.end(); ++it) {
        numResources += student.getResource(it->second);
    }
    if(numResources < 10) {
        return;
    }
    //output
    cout << "Student"
    << COLOUR_TO_STRING.at(students[j]->getColour())
    << " loses " << numResources << "resources to the geese. They lose:" << endl;

    //make student lose resources
    vector<bool> toLose; //vector for which resoruces to lose
    //figure out which resources to lose
    for(int i = 0; i < numResources; ++i) {
        if(i < numResources / 2){
            toLose.emplace_back(true);
        } else {
            toLose.emplace_back(false);
        }
    }
    std::random_shuffle(toLose.begin(), toLose.end());
    //call removeResource functions for appropriate resources
    int index = 0; //index through the toLose vector
    for(auto it = RESOURCE_TYPE_STRINGS.begin(); it != RESOURCE_TYPE_STRINGS.end(); ++it) {
        int count = student.getResource(it->second);
        int howManyLost = 0;
        for(int i = 0; i < count; ++i) {
            if(toLose.at(index)) {
                student->removeResource(it->second);
                ++howManyLost;
            }
            ++index;
        }
        cout << howManyLost << " it->second" << endl;
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

        //make each student with more than 10 resources lose to geese
        for(auto it = students.begin(); it != students.end(); ++it) {
            loseToGeese(it);
        }
        //move geese
        int geeseHere;
        bool invalid = true;
        do{
            try{
                cout << "Choose where to place the GEESE." << endl;
                if(!(cin >> geeseHere)) {
                    throw new InvalidInputException("not an integer");
                } else {
                    if(geeseHere < 0 || geeseHere > 18) {
                        throw new OutOfRangeInputException(geeseHere);
                    } else {
                        invalid = false;
                    }
                }
            } catch (InvalidInputException& e) { // not an int
                cerr << e.what() << endl;
            } catch (OutOfRangeInputException& e) { //int out of range
                cerr << e.what() << endl;
            } //end of try catch
        } while (invalid); //end of while loop
        theBoard.moveGeese(geeseHere); //geese moved!

        //TODO: steal        


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

void Gameplay::status() const {
    cout << students->status() << endl; 
}

void Gameplay::criteria() const { 
    cout << students->criteria() << endl; 
}

void Gameplay::achieve(int index) {
    theBoard->buyGoal(curPlayer, index); 
}

void Gameplay::complete(int index) {
    theBoard->buyCriteria(curPlayer, index); 
}

void Gameplay::improve(int index) {
    theBoard->improveCriteria(curPlayer, index); 
}

void Gameplay::trade(Colour receivingStudent, ResourceType give, ResourceType take) {
    cout << colourToString(curPlayer.getColour()) << " offers " << colourToString(receivingStudent) << 
        " one " << resourceTypeToString(give) << " for one " << resourceTypeToString(take) << ". "; 
    cout << "\nDoes " << colourToString(receivingStudent) << " accept this offer?" << endl; 
    
    string response;
    cout << ">"; 
    cin >> response;
    if (response == "yes") { 
        theBoard->trade(curPlayer, receivingStudent, give, take);
        cout << "Trade Successful.\n";
    }
    else if (response == "no") cout << "Trade declined." << endl;
}

void Gameplay::next() {
    whoseTurn = (whoseTurn + 1) % 4;
    curPlayer = students[whoseTurn].get();
}

void Gameplay::save(string file) {
    ofstream myFile(file); 
    if (myFile.is_open()) {
        myFile << whoseTurn; 
        myFIle << "\n"; 
        for (auto &p : student) myFile << p->save() + "\n"; 
        myFile << theBoard->save() + "\n"; 
    }
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

void endTurn() {
    while (!gameOver()) {
        cout << ">"; 
        string line; 
        getline(cin, line); 

        if (cin.eof()) {
            save("backup.sv"); 
            break; 
        } 

        istringstream iss{line}; 
        string cmd; 
        iss >> cmd; 

        if (cmd == "board") {
            board(); 
        } else if (cmd == "status") {
            status(); 
        } else if (cmd == "criteria") {
            criteria(); 
        } else if (cmd == "achieve") {
            int index; 
            iss >> index; 
            achieve(curPlayer, index); 
        } else if (cmd == "complete") {
            int index; 
            iss >> index; 
            complete(curPlayer, index); 
        } else if (cmd == "improve") {
            int index; 
            iss >> index; 
            control->improve(index); 
        } else if (cmd == "trade") {
            string colour, give, take; 
            iss >> colour; 
            iss >> give; 
            iss >> take; 
            trade(stringToColour(curPlayer), stringToColour(colour), stringToResourceType(give), stringToResourceType(take)); 
        } else if (cmd == "next") {
            next(); 
            break; 
        } else if (cmd == "save") {
            string fileName; 
            iss >> fileName; 
            if (file == "") {
                // TODO: throw exception?
            } else {
                save(fileName); 
            } 
        } else if (cmd == "help") {
            help(); 
        } else { 
            cout << "Invalid command" << endl; 
        } 
    }
}

bool endGame() {
    while (true) { 
        cout << "Would you like to play again?" << endl;
        cout << ">"; 
        string response; 
        cin >> response; 
        if (cin.eof()) {
            save("backup.sv"); 
            break; 
        } else if (response == "yes") {
            return false; 
        } else if (response == "no") {
            return true; 
        } else { 
            cout << "Invalid command." << endl; 
        }
    }
    return true; 
}

