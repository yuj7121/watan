#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <string> 
#include <array> 
#include <vector>
#include "observer.h"
#include "board.h"

struct printTile { 
    int index; 
    int value; 
    string resource; 
};

class TextDisplay : public Observer {
    vector<string> criterias;
    vector<string> goals;
    vector<printTile> resources;
    int gooseIndex; 

    void createBoard(vector<pair<string, int>> &board); 
    string printSpaces(int num) const; 
    string printTileTop(bool left, bool right);
    string printTileBottom(bool left, bool right);

    string printTileIndex(int index) const; 
    string printTileResource(int index) const; 
    string printTileValue(int index) const; 
    string printGoose(int index) const; 
    string printCriteria(int index) const; 
    string printHorizontalGoal(int index) const; 
public:
    TextDisplay(vector<pair<int, int>> &board); 

    void notify(Goal &g) override; 
    void notify(Criteria &c) override; 
    friend ostream& operator<< (ostream &out, TextDisplay &td); 
    void createTile(int id, int resource, int val); 
    void moveGoose(int index);

    void updateGoal(int goalIndex, int studentIndex);
    void updateCriterion(int criterionIndex, int studentIndex);
    void updateGeese(int tileIndex);

};

#endif
