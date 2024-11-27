#include "textDisplay.h"

string TextDisplay::printSpaces(int num) const { 
    string output; 
    for (int i = 0; i < num; ++i) {
        output += " "; 
    } 
    return output; 
}

string TextDisplay::printTileIndex(int index) const {
    string output; 
    ostringstream oss; 
    int thisIndex = resources[index].index; 
    oss << thisIndex;
    if (thisIndex < 10) { 
        output = " " + oss.str(); 
    } else { 
        output = oss.str(); 
    } 
    return printSpaces(5) + output + printSpaces(4); 
}

string TextDisplay::printTileResource(int index) const {
    return "/" + printSpaces(5) + resources[index].resource + spaces(9-resource[index].resource.length()) + "\\";
}

string TextDisplay::printTileValue(int index) const { 
    string output; 
    ostringstream oss; 
    int thisValue = resources[index].value; 
    oss << thisValue; 
    if (thisValue == 7) { //netflix, no value
        output = " "; 
    } else if (thisValue < 10) { 
        output = " " + oss.str(); 
    } else { 
        output = oss.str(); 
    } 
    return printSpaces(6) + oss + printSpaces(6); 
}

string TextDisplay::printGoose(int index) const { 
    string output; 
    output = "\\" + printSpaces(5); 
    if (index == gooseIndex) {
        output += "GEESE" + printSpaces(4); 
    } else {
        output += printSpaces(9) + "/"; 
    } 
    return output; 
}
string TextDisplay::printCriteria(int index) const { 
    return "|" + criterias[index] + "|"; 
}

string TextDisplay::printHorizontalGoal(int index) const {
    return "--" + goals[index] + "--"; 
}


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
