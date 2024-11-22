#ifndef BOARDDISPLAY_H
#define BOARDDISPLAY_H

#include <iostream>
#include <memory>

#include "observer.h"

class Board;

class BoardDisplay : public Observer {
public:
    virtual ~BoardDisplay() = default;

    virtual void updateGoal(int goalIndex, int studentIndex) = 0;
    virtual void updateCriterion(int criterionIndex, int studentIndex) = 0;
    virtual void updateGeese(int tileIndex) = 0;

    virtual void printBoard(const Board &board) const = 0;
};

#endif
