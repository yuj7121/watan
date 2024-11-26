#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <sstream> 
#include <string> 
#include "board.h"
#include "dice.h"
#include "boardsetup.h"
#include "constants.h"
#include "student.h"

using namespace std; 

class Gameplay {
    const int winVictoryPoints = 10;
    std::unique_ptr<TextDisplay> textDisplay;
    std::unique_ptr<Board> theBoard;
    std::vector<std::unique_ptr<Student>> Students;
    std::unique_ptr<Dice> dice;
    std::default_random_engine *eng;

    int whoseTurn; 
    int winnerIndex; 

public: 
    Gameplay(); 

    // TODO: need to implement
    void newGame();
    void loadGame(const std::string file);
    void loadBoard(const std::string file);

    // val = loaded dice value (type == false)
    // type is true if fair, and false if loaded
    void rollDice(int val = -1, bool type); 

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
	void trade(Student s, Resource give, Resource take); // user will input colour, and two resources, so check parameters?
	void next();
	void save(const std::string file, const bool rolledAlready = true) const;
	void help() const;

}; 

#endif