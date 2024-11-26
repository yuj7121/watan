#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <sstream> 
#include <string> 
#include "board.h"
#include "dice.h"
#include "boardsetup.h"
#include "constants.h"

using namespace std; 

class Controller {
    const int winVictoryPoints = 10;
    std::unique_ptr<Board> theBoard;
    std::unique_ptr<Dice> dice;
    std::default_random_engine *eng;
public: 
    Controller(); 

    void newGame();
    void loadGame(const std::string file);
    void loadBoard(const std::string file);

    // val = loaded dice value (type == false)
    // type is true if fair, and false if loaded
    void rollDice(int val = -1, bool type); 
}; 

#endif