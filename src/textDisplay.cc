#include "textdisplay.h"

TextDisplay::TextDisplay(std::shared_ptr<Board> board) : board(board) {
    board->attach(std::make_shared<TextDisplay>(*this));
}

void TextDisplay::updateGoal(int goalIndex, int studentIndex) {
    std::cout << "Goal " << goalIndex << " now belongs to Student " << studentIndex << ".\n";
}

void TextDisplay::updateCriterion(int criterionIndex, int studentIndex) {
    std::cout << "Criterion " << criterionIndex << " improved by Student " << studentIndex << ".\n";
}

void TextDisplay::updateGeese(int tileIndex) {
    std::cout << "Geese moved to Tile " << tileIndex << ".\n";
}

void TextDisplay::printBoard(const Board &board) const {
    // TODO: Print the board.
}
