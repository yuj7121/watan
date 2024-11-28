#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <sstream> 
#include <string> 
#include <utility>
#include <fstream>
#include <sstream>
#include <random>

#include "board.h"
#include "dice.h"
#include "boardSetup.h"
#include "randomSetup.h"
#include "fileSetup.h"
#include "constants.h"
#include "student.h"
#include "textDisplay.h"
#include "boardSetup.h"

using namespace std; 

class Gameplay {
    const int VICTORY_PTS_TO_WIN = 10;
    std::unique_ptr<TextDisplay> textDisplay;
    std::shared_ptr<Board> theBoard;
    std::vector<std::unique_ptr<Student>> students;
    std::unique_ptr<Dice> dice;
    std::unique_ptr<BoardSetup> setup;
    std::unique_ptr<default_random_engine> eng;

    Student *curPlayer; 
    int whoseTurn; 
    int winnerIndex; 


public: 
    Gameplay(); 

    // TODO: need to implement
    void newGame(int seed);
    void loadGame(const std::string file);
    void loadBoard(const std::string file);

    // val = loaded dice value (type == false)
    // type is true if fair, and false if loaded
    void rollDice(int val = -1, bool isFairDice = false);

    string curTurn() const; 
    bool gameOver() const; 
    string whoWon() const; // TODO: NEEDED?

    // end of turn commands - NEED TO IMPLEMENT
    void board() const;
	void status() const;
	void criteria() const;
	void achieve(int index);
	void complete(int index);  
	void improve(int index);
	void trade(Colour receivingStudent, ResourceType give, ResourceType take); // user will input colour, and two resources, so check parameters?
	void next();
	void save(string file); 
	void help() const;

    void initialAssignments();
    void beginTurn(Student& s);
    void endTurn(); 
    bool endGame(); 
}; 

#endif