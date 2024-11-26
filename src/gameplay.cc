#include <utility>
#include <fstream>
#include <sstream>
#include <random>
#include "controller.h"
#include "board.h"
#include "dice.h"
#include "textdisplay.h"
#include "student.h"

using namespace std; 

Gameplay::Gameplay() {}

void Gameplay::newGame() {
    array<pair<int, int>, 19> arg;
	array<int, 6> availableResources{ {3, 3, 4, 4, 4, 1} };
	array<int, 12> availableValues{ {0, 1, 2, 2, 2, 2, 0, 2, 2, 2, 2, 1} };
}

void Gameplay::rollDice(int val = -1, bool type) {
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