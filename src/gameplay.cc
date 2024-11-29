#include "gameplay.h"


using namespace std; 

Gameplay::Gameplay(int seed) : theBoard{make_shared<Board>()}, eng{make_shared<default_random_engine>(seed)}, whoseTurn{0} {
    newGame(seed); 
    initGame();
    srand(seed);
    theBoard->moveGeese(std::rand() % 18);
}

Gameplay::Gameplay(SetupType st, string fileName) : theBoard{make_shared<Board>()}, eng{make_shared<default_random_engine>()}, whoseTurn{0}{
    if (st == SetupType::LoadFromFile) {
        loadGame(fileName); 
    } else {
        loadBoard(fileName); 
    }
    initGame();
}

void Gameplay::initGame() {
    students.push_back(make_shared<Student>(Colour::BLUE));
    students.push_back(make_shared<Student>(Colour::RED));
    students.push_back(make_shared<Student>(Colour::ORANGE));
    students.push_back(make_shared<Student>(Colour::YELLOW));
    curPlayer = students.at(whoseTurn);
    winnerIndex = -1;
}

GameState Gameplay::getState() {
    return GameState{students, theBoard, curPlayer}; 
}

vector<shared_ptr<Student>> Gameplay::getStudents() const { 
    return students; 
}

shared_ptr<Board> Gameplay::getBoard() const {
    return theBoard; 
}

shared_ptr<Student> Gameplay::getCurPlayer() const {
    return curPlayer; 
}

int Gameplay::getGooseIndex() const {
    return theBoard->getGeese(); 
}

void Gameplay::newGame(int seed) {
    shared_ptr<RandomSetup> setup = std::make_shared<RandomSetup>(seed);
    setup->setup(theBoard); 
    // TODO: text display and board display
}

void Gameplay::loadGame(const std::string file) { 
    ifstream f{file};
    // TODO: check types 
    vector<vector<int>> studentResources(4, vector<int>(5));
    vector<vector<int>> studentGoals(4);
    vector<vector<pair<int, int>>> studentCriteria(4);
    int curTurn = 0;
    for (int i = 0; i < 7; ++i) {
        string line; 
        getline(f, line); 
        istringstream iss{line}; 
        int input; 
        while (iss >> input) {
            // curTurn
            if (i == 0) {
                if(input >= 0 && input < NUM_STUDENTS) {
                    curTurn = input;
                }
            // studentData
           } else if (i >= 1 && i <= 4) {
                int playerIndex = i - 1; 
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
                    if(!iss >> input){
                        break;
                    } 
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
                shared_ptr<FileSetup> setup = std::make_shared<FileSetup>(file); 
                setup->setup(theBoard); 
            } else {
                theBoard->moveGeese(input); //asddddddd
            }
        }
    }
    whoseTurn = curTurn;
    // TODO: text display and board display
}

void Gameplay::loadBoard(const std::string file) {
    shared_ptr<FileSetup> setup = std::make_shared<FileSetup>(file); 
    setup->setup(theBoard); 
    // TODO: text display and board display 
}

void Gameplay::loseToGeese(std::shared_ptr<Student> student) {
    int numResources = 0; //total number of resources the student has
    //find the total number of resources
    for(auto it = RESOURCE_TYPE_STRINGS.begin(); it != RESOURCE_TYPE_STRINGS.end(); ++it) {
        numResources += student->getResource(it->first);
    }
    if(numResources < 10) {
        return;
    }
    //output
    cout << "Student"
    << COLOUR_TO_STRING.at(student->getColour())
    << " loses " << numResources / 2 << "resources to the geese. They lose:" << endl;

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
        int count = student->getResource(it->first);
        int howManyLost = 0;
        for(int i = 0; i < count; ++i) {
            if(toLose.at(index)) {
                student->removeResource(it->first);
                ++howManyLost;
            }
            ++index;
        }
        cout << howManyLost << " " << it->second << endl;
    }
}

//a helper function that does case-insensitive string comparison
bool Gameplay::noCaseStrCmp(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;
    int len = str1.length();
    for (int i = 0; i < len; ++i) {
        if (tolower(str1[i]) != tolower(str2[i]))
            return false;
    }
    return true;
}

int Gameplay::convertColourInput(string input) {
    int colour = -1;
    if(noCaseStrCmp(input, "Blue")) {
        colour = 0;
    } else if(noCaseStrCmp(input, "Red")){
        colour = 1;
    } else if(noCaseStrCmp(input, "Orange")){
        colour = 2;
    } else if(noCaseStrCmp(input, "Yellow")){
        colour = 3;
    }
    return colour;
}

//helper function that is called when you rool 7
void Gameplay::geeseLanded() {
    //make each student with more than 10 resources lose to geese
    for(auto it = students.begin(); it != students.end(); ++it) {
        loseToGeese(*it);
    }
    //move geese
    int geeseHere;
    bool invalid = true;
    do{
        try{
            cout << "Choose where to place the GEESE." << endl << "> ";
            if(!(cin >> geeseHere)) {
                throw new InvalidInputException("not an integer");
            } else {
                if(geeseHere < 0 || geeseHere > 18) {
                    throw new OutOfRangeInputException(std::to_string(geeseHere));
                } else if(geeseHere == theBoard->getGeese()) {
                    throw InvalidGeesePlacementException("Geese are already on this tile!");
                } else {
                    invalid = false;
                }
            }
        } catch (const  InvalidInputException& e) { // not an int
            cerr << e.what() << endl;
        } catch (const  OutOfRangeInputException& e) { //int out of range
            cerr << e.what() << endl;
        } catch (const  InvalidGeesePlacementException& e) {
            cerr << e.what() << endl;
        }//end of try catch
    } while (invalid); //end of while loop
    theBoard->moveGeese(geeseHere); //geese moved!

    //check who can be stolen from
    bool canSteal[NUM_STUDENTS];
    bool noOneToSteal = true;
    for(int i = 0; i < NUM_STUDENTS; ++i) {
        if(students.at(i)->getIndex() == curPlayer->getIndex()) {
            canSteal[i] = false;
        } else if(theBoard->tileHasStudent(geeseHere, students.at(i))){
            canSteal[i] = true;
            noOneToSteal = false;
        } else {
            canSteal[i] = false;
        }
    }
    if(noOneToSteal) {
        cout << "Student "+ colourToString(curPlayer->getColour()) + " has no students to steal from." << endl;
    } else{
        //if you can steal
        cout << "Student " + colourToString(curPlayer->getColour()) + " can choose to steal from ";
        bool first = true;
        for(int i = 0; i < NUM_STUDENTS; ++i) {
            if(canSteal[i]){
                if (!first) {
                    cout << ", ";
                } else {
                    first = false;
                }
                cout << colourToString((students.at(i))->getColour());
            }
        }
        cout << "." << endl;
    }

    //take in who to steal from
    int toSteal;
    invalid = true;
    do{
        try{
            string str;
            cout << "Choose a student to steal from." << endl << "> ";
            if(!(cin >> str)) {
                throw new InvalidInputException("Read failed.");
            } else {
                toSteal = convertColourInput(str);
                if(toSteal == -1) {
                    throw new InvalidInputException(str);
                } else if(toSteal == curPlayer->getIndex()) {
                    throw new InvalidInputException("You can't steal from yourself!");
                } else {
                    invalid = false;
                }
            }
        } catch (InvalidInputException& e) { //invalid input
            cerr << e.what() << endl;
        } //end of try catch
    } while (invalid); //end of while loop

    //steal from that student!
    //probability = numRes/total num res
    int totalRes = 0; //total number of resources the student being stollen from has
    for(auto it = RESOURCE_TYPE_STRINGS.begin(); it != RESOURCE_TYPE_STRINGS.end(); ++it) {
        totalRes += (students.at(toSteal))->getResource(it->first);
    }
    for(auto it = RESOURCE_TYPE_STRINGS.begin(); it != RESOURCE_TYPE_STRINGS.end(); ++it) {
        int randomNumber = 0;
        randomNumber = (std::rand() % (100));
        //if the random roll succeeds, you steal!
        if(totalRes != 0 && randomNumber <= ((100 * (students.at(toSteal))->getResource(it->first)) / totalRes)) {
            (students.at(toSteal))->removeResource(it->first);
            curPlayer->getResource(it->first);
            cout << "Student " << COLOUR_TO_STRING.at(curPlayer->getColour()) << " steals "
            << it->second << " from student " << COLOUR_TO_STRING.at((students.at(toSteal))->getColour()) << "." << endl;
        }
    }
}

int Gameplay::rollDice(int val) {
    int roll; 
    if (val == -1) { // fair dice
        dice = std::make_shared<FairDice>(eng); 
        roll = dice->roll(); 
    } else { // loaded dice 
        dice = std::make_shared<LoadedDice>(val); 
        roll = dice->roll(); 
    }
    return roll; 
}

void Gameplay::distributeResource(int roll) {
    if (roll == 7) {
        // TODO: GEESE
        geeseLanded();
    } else {
        theBoard->tileRolled(roll);
    } 
}

string Gameplay::curTurn() const { 
    if (whoseTurn == 0) return "Red";
    else if (whoseTurn == 1) return "Orange";
    else if (whoseTurn == 2) return "Yellow";
    else if (whoseTurn == 3) return "Blue";
    else return "";
}

// TODO double check logic/efficiency -
bool Gameplay::gameOver() {
    for (int i = 0; i < 4; ++i) {
        if ((students[i])->calculatePoints() >= 10) {
            winnerIndex = i;
            return true;
	    }
    }
    return false;
}

void Gameplay::board() { 
    notifyObservers(GameEvent::BoardInfo); 
}

void Gameplay::status() {
    notifyObservers(GameEvent::PlayersStatus);
}

void Gameplay::criteria() { 
    notifyObservers(GameEvent::PlayerCriteria); 
}

string Gameplay::getLastErrorMessage() const {
    return lastErrorMessage; 
}

void Gameplay::achieve(int index) {
    try {
        theBoard->buyGoal(curPlayer, index); 
        lastErrorMessage = ""; 
        lastAchievedGoal = theBoard->getGoals()[index]; 
    } catch (exception &e) {
        lastErrorMessage = e.what(); 
    }
    notifyObservers(GameEvent::Achieve);
}

void Gameplay::complete(int index) {
    // TODO: if start of game, 
    try {
        theBoard->buyCriteria(curPlayer, index); 
        lastErrorMessage = ""; 
    } catch (exception &e) {
        lastErrorMessage = e.what(); 
    }
    notifyObservers(GameEvent::Complete); 
}

void Gameplay::improve(int index) {
    try {
        theBoard->improveCriteria(curPlayer, index); 
        lastErrorMessage = ""; 
    } catch (exception &e) {
        lastErrorMessage = e.what(); 
    }
    notifyObservers(GameEvent::Improve); 
}

void Gameplay::trade(shared_ptr<Student> offeringStudent, string colour, string give, string take) {
    shared_ptr<Student> receivingStudent = students.at(convertColourInput(colour));
    if(receivingStudent->getIndex() == curPlayer->getIndex()) {
        throw new InvalidCommandException(""); 
    }
    ResourceType giveType = stringToResourceType(give);
    ResourceType takeType = stringToResourceType(take);
    if(giveType == ResourceType::ERROR || takeType == ResourceType::ERROR) {
        throw new InvalidCommandException(""); 
    }
    trade(offeringStudent, receivingStudent, giveType, takeType); 
}

void Gameplay::trade(shared_ptr<Student> offeringStudent, shared_ptr<Student> receivingStudent, ResourceType give, ResourceType take) {
    struct Trade t {offeringStudent, receivingStudent, give, take, ""}; 
    notifyObservers(GameEvent::TradeResource, t); 
    
    string response;
    cin >> response;
    if (noCaseStrCmp(response, "yes")) { 
        offeringStudent->trade(receivingStudent, give, take);
        t.result == "Trade Successful.\n";
    }
    else if (noCaseStrCmp(response, "no")) t.result = "Trade declined.";
    notifyObservers(GameEvent::TradeResource, t); 
}

void Gameplay::save(string file) {
    ofstream myFile(file); 
    if (myFile.is_open()) {
        myFile << whoseTurn; 
        myFile << "\n";  
        for (auto &p : students) myFile << p->save() + "\n"; 
        myFile << theBoard->save() + "\n"; 
    }
}

void Gameplay::initialAssignments() {
    bool reverse = false; 
    int i = 0; 
    
    while (i >= 0 && i < NUM_STUDENTS) {
		cout << "Student " << COLOUR_TO_STRING.at(students[i]->getColour())
            << ", where do you want to complete an Assignment?" << endl << "> ";
        string str;
        int index;
        cin >> str;
        try{
            try {
                index = stoi(str);
            } catch (std::invalid_argument& e) {
                throw InvalidInputException("not an integer");
            }
        } catch (InvalidInputException& e) {
            cout << e.what() << endl;
			continue;
        }
        if (index >= 0 && index <= 53) {
            try {
                shared_ptr<Student> tempStudent = students.at(i);
                theBoard->sogBuyCriteria(tempStudent, index);
                //cout << i << endl; 
            } catch (InvalidInputException &err) {
                cout << err.what() << endl;
                continue;
            } catch (AdjacentPlacementException &err) {
                cout << err.what() << endl;
                continue;
            } catch (AlreadyOwnedException &err) {
                cout << err.what() << endl;
                continue;
            }
        } else {
            cout << to_string(index) << " is not a valid "
                << "intersection index. It must be "
                << "between 0 and " << NUM_CRITERION - 1 
                << "."  << endl;
            continue;
        }

		if (i == NUM_STUDENTS - 1 && !reverse) {
            i++;
            reverse = true;
        } else if (i == 0 && reverse) {
            break; // all students have had their start turns
        }
        reverse ? --i : ++i;

	}
}//end of function


int Gameplay::beginTurn(shared_ptr<Student> student) {
    cout << "Student " << COLOUR_TO_STRING.at(student->getColour()) << "'s turn." << endl;

    string input;
    int val = -1;
    //get dice type
    do {
        try{
            cout << "> ";
            cin >> input;
            cout << "(1) input: " << input << endl;
            //if user wants loaded
            if (input == "load") {
                int invalid = true;
                cout << "Input a roll between 2 and 12:" << endl;
                while (invalid) {
                    try {
                        cout << "> ";
                        string str;
                        cin >> str;
                        try {
                            val = stoi(str);
                        } catch (std::invalid_argument& e) {
                            throw InvalidInputException("not an integer");
                        }
                        if(val < 2 || val > 12) {
                            // throw invalidInputException instead 
                            throw OutOfRangeInputException(std::to_string(val));
                        } else {
                            invalid = false;
                        }
                    } catch (const InvalidInputException& e) { // not an int
                        cerr << e.what() << endl;
                    } catch (OutOfRangeInputException& e) { //int out of range
                        cerr << e.what() << endl;
                    } //end of try catch
                } //end of while
                //rollDice(val, false);
                //if user wants fair            
            } else if (input == "fair") {
                val = -1;
            } else if (input == "roll") {
                return rollDice(val);
            } else {
                cout << "input: " << input << endl;
                throw InvalidInputException(input);
            }
        } catch (InvalidInputException& e) { //invalid input for what to do
            cerr << e.what() << endl;
        } //end of try catch
    } while (true); //end of while loop
    // cout << "val = " << val << endl;
    return -1;
}//end of function

void Gameplay::endTurn() {
    whoseTurn = (whoseTurn + 1) % NUM_STUDENTS; // TODO: constant of # of players 
    curPlayer = students[whoseTurn];
}

void Gameplay::play() {
    while (!gameOver()) {
        int roll = beginTurn(curPlayer);
        distributeResource(roll);
        while (true) {
            string line; 
            cout << "> "; 
            getline(cin, line); 

            istringstream iss{line}; 
            string cmd; 
            iss >> cmd; 
            try{
                if (cmd == "board") {
                    board(); 
                } else if (cmd == "status") {
                    status(); 
                    cout << endl;
                } else if (cmd == "criteria") {
                    criteria(); 
                } else if (cmd == "achieve") {
                    int index;
                    iss >> index; 
                    if(index < 0 || index > NUM_GOALS) {
                        throw InvalidCommandException(""); 
                    }
                    achieve(index); 
                } else if (cmd == "complete") {
                    int index;
                    iss >> index;
                    if(index < 0 || index > NUM_CRITERION) {
                        throw InvalidCommandException(""); 
                    }
                    complete(index); 
                } else if (cmd == "improve") {
                    int index; 
                    iss >> index; 
                    if(index < 0 || index > NUM_CRITERION) {
                        throw InvalidCommandException(""); 
                    }
                    improve(index); 
                } else if (cmd == "trade") {
                    string colour, give, take; 
                    iss >> colour; 
                    iss >> give; 
                    iss >> take; 
                    trade(curPlayer, colour, give, take); 
                } else if (cmd == "next") {
                    break; 
                } else if (cmd == "save") {
                    string fileName;
                    iss >> fileName; 
                    if (fileName == "") {
                        // TODO: throw exception?
                        throw InvalidCommandException("file name not valid"); 
                    } else {
                        Gameplay::save(fileName); 
                    } 
                } else if (cmd == "help") {
                    notifyObservers(GameEvent::Help); 
                } else { 
                    throw InvalidCommandException("Invalid command."); 
                } //end of it
            } catch (InvalidCommandException& e){
                cerr << e.what() << endl << endl;
            } catch (NonAdjacentPlacementException& e) {
                cerr << e.what() << endl << endl;
            } catch (AlreadyOwnedException& e) {
                cerr << e.what() << endl << endl;
            } catch (InsufficientResourcesException& e) {
                cerr << e.what() << endl << endl;
            } catch (InvalidCriteriaImprovementException& e) {
                cerr << e.what() << endl << endl;
            } //end of catch
        } //end of while
        endTurn();
    }
    save("backup.sv"); 
}
