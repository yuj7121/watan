#include "textDisplay.h"

string TextDisplay::printSpaces(int num) const { 
    string output; 
    for (int i = 0; i < num; ++i) {
        output += " "; 
    } 
    return output; 
}

string printTileTop(bool left = true, bool right = true) {
    string output; 
    if (left) {
        output += "/"; 
    } else { 
        output += ""; 
    }
    output += printSpaces(11); 
    if (right) {
        output += "\\"; 
    } else { 
        output += ""; 
    } 
    return output; 
}

string printTileBottom(bool left = true, bool right = true) {
    string output; 
    if (right) {
        output += "/"; 
    } else { 
        output += ""; 
    }
    output += printSpaces(11); 
    if (left) {
        output += "\\"; 
    } else { 
        output += ""; 
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

ostream & operator<<(ostream &out, const TextDisplay &td) {
    out << printSpaces(35); 
    out << td.printCriteria(0) + td.printHorizontalGoal(0) + td.printCriteria(1) << endl; 

    out << printSpaces(35); 
    out << printTileTop() << endl; 

    out << printSpaces(33); 
    out << td.goals[1] << td.printTileIndex(0) << td.goals[2] << endl; 

    out << printSpaces(33); 
    out << td.printTileResource(0) << endl; 

    out << printSpaces(20); 
    out << td.printCriteria(2) + td.printHorizontalGoal(3) + td.printCriteria(3) + td.printTileValue(0) 
        + td.printCriteria(4) + td.printHorizontalGoal(4) + td.printCriteria(5) << endl; 

    out << printSpaces(20); 
    out << printTileTop(1, 0) + td.printGoose(0) + printTileTop(0, 1) << endl; 

    out << printSpaces(18); 
    out << td.goals[5] + td.printTileIndex(1) + td.goals[6] + printSpaces(12) + td.goals[7] 
        + td.printTileIndex(2) + td.goals[8] << endl; 

    out << printSpaces(18);
    out << td.printTileResource(1) + printTileBottom(0, 0) + td.printTileResource(2) << endl;

    out << printSpaces(5);
    out << td.printCriteria(6) + td.printHorizontalGoal(9) + td.printCriteria(7)
        + td.printTileValue(1) + td.printCriteria(8) + td.printHorizontalGoal(10)
        + td.printCriteria(9) + td.printTileValue(2) + td.printCriteria(10)
        + td.printHorizontalGoal(11) + td.printCriteria(11) << endl;

    out << printSpaces(5);
    out << printTileTop(1, 0) + td.printGoose(1) + printTileTop(0, 0)
        + td.printGoose(2) + printTileTop(0, 1) << endl;
    
    out << printSpaces(3);
    out << td.goals[12] + td.printTileIndex(3) + td.goals[13] + printSpaces(12)
        + td.goals[14] + td.printTileIndex(4) + td.goals[15] + printSpaces(12)
        + td.goals[16] + td.printTileIndex(5) + td.goals[17] << endl;

    out << printSpaces(3);
    out << td.printTileResource(3) + printTileBottom(0, 0) + td.printTileResource(4)
        + printTileBottom(0, 0) + td.printTileResource(5) << endl;

    out << " " + td.printCriteria(12) + td.printTileValue(3) + td.printCriteria(13)
        + td.printHorizontalGoal(18) + td.printCriteria(14) + td.printTileValue(4)
        + td.printCriteria(15) + td.printHorizontalGoal(19) + td.printCriteria(16)
        + td.printTileValue(5) + td.printCriteria(17) << endl;

    out << printSpaces(3);
    out << td.printGoose(3) + printTileTop(0, 0) + td.printGoose(4)
        +  printTileTop(0, 0) + td.printGoose(5) << endl;

    out << printSpaces(3);
    out << td.goals[20] + printSpaces(12) + td.goals[21] + td.printTileIndex(6)
        + td.goals[22] + printSpaces(12) + td.goals[23] + td.printTileIndex(7)
        + td.goals[24] + printSpaces(12) + td.goals[25] << endl;

    out << printSpaces(5);
    out << printTileBottom(1, 0) + td.printTileResource(6) + printTileBottom(0, 0)
        + td.printTileResource(7) + printTileBottom(0, 1) << endl;

    out << printSpaces(5);
    out << td.printCriteria(18) + td.printHorizontalGoal(26) + td.printCriteria(19)
        + td.printTileValue(6) + td.printCriteria(20) + td.printHorizontalGoal(27)
        + td.printCriteria(21) + td.printTileValue(7) + td.printCriteria(22)
        + td.printHorizontalGoal(28) + td.printCriteria(23) << endl;

    out << printSpaces(5);
    out << printTileTop(1, 0) + td.printGoose(6) + printTileTop(0, 0)
        + td.printGoose(7) + printTileTop(0, 1) << endl;

    out << printSpaces(3);
    out << td.goals[29] + td.printTileIndex(8) + td.goals[30] + printSpaces(12)
        + td.goals[31] + td.printTileIndex(9) + td.goals[32] + printSpaces(12)
        + td.goals[33] + td.printTileIndex(10) + td.goals[34] << endl;

    out << printSpaces(3);
    out << td.printTileResource(8) + printTileBottom(0, 0) + td.printTileResource(9)
        + printTileBottom(0, 0) + td.printTileResource(10) << endl;

    out << " " + td.printCriteria(24) + td.printTileValue(8) + td.printCriteria(25)
        + td.printHorizontalGoal(35) + td.printCriteria(26) + td.printTileValue(9)
        + td.printCriteria(27) + td.printHorizontalGoal(36) + td.printCriteria(28)
        + td.printTileValue(10) + td.printCriteria(29) << endl;

    out << printSpaces(3);
    out << td.printGoose(8) + printTileTop(0, 0) + td.printGoose(9)
        +  printTileTop(0, 0) + td.printGoose(10) << endl;

    out << printSpaces(3);
    out << td.goals[37] + printSpaces(12) + td.goals[38] + td.printTileIndex(11)
        + td.goals[39] + printSpaces(12) + td.goals[40] + td.printTileIndex(12)
        + td.goals[41] + printSpaces(12) + td.goals[42] << endl;

    out << printSpaces(5);
    out << printTileBottom(1, 0) + td.printTileResource(11) + printTileBottom(0, 0)
        + td.printTileResource(12) + printTileBottom(0, 1) << endl;

    out << printSpaces(5);
    out << td.printCriteria(30) + td.printHorizontalGoal(43) + td.printCriteria(31)
        + td.printTileValue(11) + td.printCriteria(32) + td.printHorizontalGoal(44)
        + td.printCriteria(33) + td.printTileValue(12) + td.printCriteria(34)
        + td.printHorizontalGoal(45) + td.printCriteria(35) << endl;

    out << printSpaces(5);
    out << printTileTop(1, 0) + td.printGoose(11) + printTileTop(0, 0)
        + td.printGoose(12) + printTileTop(0, 1) << endl;

    out << printSpaces(3);
    out << td.goals[46] + td.printTileIndex(13) + td.goals[47] + printSpaces(12)
        + td.goals[48] + td.printTileIndex(14) + td.goals[49] + printSpaces(12)
        + td.goals[50] + td.printTileIndex(15) + td.goals[51] << endl;

    out << printSpaces(3);
    out << td.printTileResource(13) + printTileBottom(0, 0) + td.printTileResource(14)
        + printTileBottom(0, 0) + td.printTileResource(15) << endl;

    out << " " + td.printCriteria(36) + td.printTileValue(13) + td.printCriteria(37)
        + td.printHorizontalGoal(52) + td.printCriteria(38) + td.printTileValue(14)
        + td.printCriteria(39) + td.printHorizontalGoal(53) + td.printCriteria(40)
        + td.printTileValue(15) + td.printCriteria(41) << endl;

    out << printSpaces(3);
    out << td.printGoose(13) + printTileTop(0, 0) + td.printGoose(14)
        +  printTileTop(0, 0) + td.printGoose(15) << endl;

    out << printSpaces(3);
    out << td.goals[54] + printSpaces(12) + td.goals[55] + td.printTileIndex(16)
        + td.goals[56] + printSpaces(12) + td.goals[57] + td.printTileIndex(17)
        + td.goals[58] + printSpaces(12) + td.goals[59] << endl;

    out << printSpaces(5);
    out << printTileBottom(1, 0) + td.printTileResource(16) + printTileBottom(0, 0)
        + td.printTileResource(17) + printTileBottom(0, 1) << endl;

    out << printSpaces(5);
    out << td.printCriteria(42) + td.printHorizontalGoal(60) + td.printCriteria(43)
        + td.printTileValue(16) + td.printCriteria(44) + td.printHorizontalGoal(61)
        + td.printCriteria(45) + td.printTileValue(17) + td.printCriteria(46)
        + td.printHorizontalGoal(62) + td.printCriteria(47) << endl;

    out << printSpaces(18);
    out << td.printGoose(16) + printTileTop(0, 0) + td.printGoose(17) << endl;

    out << printSpaces(18);
    out << td.goals[63] + printSpaces(12) + td.goals[64] + td.printTileIndex(18)
        + td.goals[65] + printSpaces(12) + td.goals[66] << endl;

    out << printSpaces(20);
    out << printTileBottom(1, 0) + td.printTileResource(18) + printTileBottom(0, 1);
    out << endl;

    out << printSpaces(20);
    out << td.printCriteria(48) + td.printHorizontalGoal(67) + td.printCriteria(49)
        + td.printTileValue(18) + td.printCriteria(50) + td.printHorizontalGoal(68)
        + td.printCriteria(51) << endl;

    out << printSpaces(33);
    out << td.printGoose(18) << endl;

    out << printSpaces(33);
    out << td.goals[69] + printSpaces(12) + td.goals[70] << endl;

    out << printSpaces(35);
    out << printTileBottom(1,1) << endl;

    out << printSpaces(35);
    out << td.printCriteria(52) + td.printHorizontalGoal(71) + td.printCriteria(53);
    out << endl;

    return out; 
}