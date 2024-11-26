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
    std::unique_ptr<Board> theBoard;
    std::vector<std::unique_ptr<Student>> Students;
    std::unique_ptr<Dice> dice;
    std::default_random_engine *eng;

    int whoseTurn; 

public: 
    Gameplay(); 

    void newGame();
    void loadGame(const std::string file);
    void loadBoard(const std::string file);

    // val = loaded dice value (type == false)
    // type is true if fair, and false if loaded
    void rollDice(int val = -1, bool type); 

    string getWhoseTurn() const; 
    bool gameOver() const; 

}; 

#endif