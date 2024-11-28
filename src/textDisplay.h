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
    vector<string> criterias(54); 
    vector<string> goals(72);
    vector<printTile> resources(19); 
    int gooseIndex; 
    void createBoard(vector<pair<int, int>> board(19)); 
    string printSpaces(int num) const; 
    string printTileIndex(int index) const; 
    string printTileResource(int index) const; 
    string printTileValue(int index) const; 
    string printGoose(int index) const; 
    string printCriteria(int index) const; 
    string printHorizontalGoal(int index) const; 
public:
    TextDisplay(vector<pair<int, int>> board(19)); 
    TextDisplay(vector<pair<int, int>> board(19), vector<int> playerGoal(4), vector<pair<int, int>> playerCriteria(4), int goose); 
    void updateGoal(int goalIndex, int studentIndex) override;
    void updateCriterion(int criterionIndex, int studentIndex) override;
    void updateGeese(int tileIndex) override;
    void printBoard(const Board &board) const override;

private:
    std::weak_ptr<Board> board;
};

#endif
