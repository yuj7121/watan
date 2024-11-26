#include <utility>
#include <fstream>
#include <sstream>
#include <random>
#include "controller.h"
#include "board.h"
#include "dice.h"
#include "textdisplay.h"

using namespace std; 

Controller::Controller() {}

void Controller::rollDice(int val = -1, bool type) {
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