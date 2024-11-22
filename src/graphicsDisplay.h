#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "boarddisplay.h"
#include "constants.h"
#include "xwindow.h"
#include "board.h"

class GraphicsDisplay : public BoardDisplay {
    Xwindow window;

public:
    GraphicsDisplay(std::shared_ptr<Board> board, int width = WINDOW_WIDTH, int height = WINDOW_HEIGHT);

    void updateGoal(int goalIndex, int studentIndex) override;
    void updateCriterion(int criterionIndex, int studentIndex) override;
    void updateGeese(int tileIndex) override;
    void printBoard(const Board &board) const override;

private:
    std::weak_ptr<Board> board;
};

#endif
