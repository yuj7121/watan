#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <sstream> 
#include <string> 
#include <utility>
#include <fstream>
#include <sstream>
#include <random>
#include <memory>

#include "board.h"
#include "dice.h"
#include "fairDice.h"
#include "loadedDice.h"
#include "boardSetup.h"
#include "randomSetup.h"
#include "fileSetup.h"
#include "constants.h"
#include "student.h"
#include "boardSetup.h"
#include "subject.h"
#include "trade.h"

using namespace std; 

class Gameplay : public Subject {
    const int VICTORY_PTS_TO_WIN = 10;
    std::shared_ptr<Board> theBoard;
    std::vector<std::shared_ptr<Student>> students;
    std::shared_ptr<Dice> dice;
    std::shared_ptr<default_random_engine> eng;

    shared_ptr<Student> curPlayer; 
    int whoseTurn; 
    int winnerIndex;
    void loseToGeese(shared_ptr<Student> student); //helper fucntion that makes each student lose resources
    void geeseLanded(); //helper function that is called when you rool 7
    bool noCaseStrCmp(string str1, string str2); //helper function that does case insensitive string comparison
//TODO: move to constant.h
    int convertColourInput(string input); //takes in a string, returns the colour, or -1 if invalid

public: 
    enum SetupType {LoadFromFile, LoadFromBoard}; 
    Gameplay(int seed); 
    Gameplay(SetupType st, string fileName);
    GameState getState() override; 

    void newGame(int seed);
    void loadGame(const std::string file);
    void loadBoard(const std::string file);

    vector<shared_ptr<Student>> getStudents() const;
    shared_ptr<Board> getBoard() const; 
    shared_ptr<Student> getCurPlayer() const; 
    string getLastErrorMessage() const; 
    void play(); 

private: 
    // val = loaded dice value (type == false)
    // type is true if fair, and false if loaded
    // void rollDice(int val = -1, bool isFairDice = false);
    void rollDice(int value); 

    string curTurn() const; 
    bool gameOver(); 
    string whoWon() const; // TODO: NEEDED?
    shared_ptr<Goal> lastAchievedGoal = nullptr; 
    string lastErrorMessage = ""; 

    // end of turn commands - NEED TO IMPLEMENT
    void board();
	void status();
	void criteria();
	void achieve(int index);
	void complete(int index);  
	void improve(int index);
	void trade(shared_ptr<Student> offeringStudent, shared_ptr<Student> receivingStudent, ResourceType give, ResourceType take); // user will input colour, and two resources, so check parameters?
	void trade(shared_ptr<Student> offeringStudent, string colour, string give, string take);

    void distributeResource();
	void save(string file); 

    void initialAssignments();
    void beginTurn(shared_ptr<Student> student);
    void endTurn(); 
}; 

#endif