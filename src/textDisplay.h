#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>

#include "boardDisplay.h"
#include "board.h"

class TextDisplay : public BoardDisplay {
public:
    TextDisplay(std::shared_ptr<Board> board);
    void updateGoal(int goalIndex, int studentIndex) override;
    void updateCriterion(int criterionIndex, int studentIndex) override;
    void updateGeese(int tileIndex) override;
    void printBoard(const Board &board) const override;

private:
    std::weak_ptr<Board> board;
};

#endif
