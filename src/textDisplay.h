#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <string> 
#include <array> 
#include <vector>
#include "observer.h"
#include "board.h"
#include "trade.h"

class Gameplay; 

class TextDisplay : public Observer {
    shared_ptr<Gameplay> gp; 
    void help() const;

    string printTileIndex(int index) const; 
    string printTileResource(int index) const; 
    string printTileValue(int index) const; 
    string printGoose(int index) const; 
    string printGoal(shared_ptr<Goal> g) const;
    string printCriteria(shared_ptr<Criteria> c) const; 
    string printHorizontalGoal(shared_ptr<Goal> g) const; 
    void printBoard(shared_ptr<Board> b) const; 
public:
    TextDisplay(shared_ptr<Gameplay> gp); 

    void notify(GameEvent ge) override; 
    void notify(GameEvent ge, Trade t) override; 
    //void notify(Criteria &c) override; 
    //friend ostream& operator<< (ostream &out, TextDisplay &td); 
    // void createTile(int id, string resource, int val); 
    // void moveGoose(int index);
    //friend ostream& operator << (ostream&out, const TextDisplay &td);
};


#endif
