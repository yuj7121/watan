#include "textDisplay.h"
#include "gameplay.h"

void TextDisplay::help() const {
    cout << "Valid commands:" << endl
        << "board" << endl
        << "status" << endl
        << "criteria" << endl
        << "achieve <goal>" << endl
        << "complete <criterion>" << endl
        << "improve <criterion>" << endl
        << "trade <colour> <give> <take>" << endl
        << "next" << endl
        << "save <file>" << endl
        << "help" << endl;
}

// void TextDisplay::createTile(int id, string resource, int val) {
//     resources[id] = printTile{id, resourceTypes[resource], val};
// }

// void TextDisplay::createBoard(vector<pair<string, int>> &board) {
//     for (int i = 0; i < 54; ++i) {
//         ostringstream oss;
//         oss << i;
//         if (i < 10) {
//             criterias[i] = " " + oss.str();
//         } else {
//             criterias[i] = oss.str();
//         }
//     }
//     for (int i = 0; i < 72; ++i) {
//         ostringstream oss;
//         oss << i;
//         if (i < 10) {
//             goals[i] = " " + oss.str();
//         } else {
//             goals[i] = oss.str();
//         }
//     }
//     for (int i = 0; i < 19; ++i) {
//         createTile(i, board[i].first, board[i].second);
//     }
// }

TextDisplay::TextDisplay(shared_ptr<Gameplay> gp) {
    this->gp = gp;
}

// TODO: any additional information -> end of turn command lines
void TextDisplay::notify(GameEvent ge) {
    // goals[g.getIndex()] = g.getState();
    if (ge == GameEvent::Help) {
        help(); 
    } else if (ge == GameEvent::PlayersStatus) {
        for (auto it = gp->getState().students.begin(); it != gp->getState().students.end(); ++it) {
            cout << (*it)->status();  
        }
    } else if (ge == GameEvent::BoardInfo) {
        // cout << gp->getBoard();
        cout << gp->getState().theBoard;
    } else if (ge == GameEvent::Achieve) {
        /*
        if (gp->getLastErrorMessage() == "") {
            cout << "player" << gp->getCurStudent()->getColour() << "has achieved" << gp->getLastAchievedGoal(); 
        } else {
            cout << gp->getLastErrorMessage(); 
        }
        */
       cout << gp->getBoard(); 
       if (gp->getLastErrorMessage() != "") {
            cout << gp->getLastErrorMessage(); 
        }
    }
}

void TextDisplay::notify(GameEvent ge, Trade t) {
    if (ge == GameEvent::TradeResource) {
        if (t.result == "") {
            cout << colourToString(t.student1->getColour()) << " offers " << colourToString(t.student2->getColour()) << 
            " one " << resourceTypeToString(t.resource1) << " for one " << resourceTypeToString(t.resource2) << ". "; 
            cout << "\nDoes " << colourToString(t.student2->getColour()) << " accept this offer?" << endl;
            cout << ">";  
        } else {
            cout << t.result << endl; 
        }
    }
}

string printSpaces(int num) { 
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
    // string output; 
    // ostringstream oss; 
    // int thisIndex = resources[index].index; 
    // oss << thisIndex;
    // if (thisIndex < 10) { 
    //     output = " " + oss.str(); 
    // } else { 
    //     output = oss.str(); 
    // } 
    // return printSpaces(5) + output + printSpaces(4); 
    return "";
}

string TextDisplay::printTileResource(int index) const {
    // return "/" + printSpaces(5) + resources[index].resource + printSpaces(9-resources[index].resource.length()) + "\\";
    return "";
}

string TextDisplay::printTileValue(int index) const { 
    // string output; 
    // ostringstream oss; 
    // int thisValue = resources[index].value; 
    // oss << thisValue; 
    // if (thisValue == 7) { //netflix, no value
    //     output = " "; 
    // } else if (thisValue < 10) { 
    //     output = " " + oss.str(); 
    // } else { 
    //     output = oss.str(); 
    // } 
    // return printSpaces(6) + output + printSpaces(6); 
    return "";
}

string TextDisplay::printGoose(int index) const { 
    string output; 
    output = "\\" + printSpaces(5); 
    // if (index == gooseIndex) {
    //     output += "GEESE" + printSpaces(4); 
    // } else {
    //     output += printSpaces(9) + "/"; 
    // } 
    return output; 
}

string TextDisplay::printCriteria(shared_ptr<Criteria> c) const { 
    return "|" + c->info() + "|"; 
}

string TextDisplay::printHorizontalGoal(shared_ptr<Goal> g) const {
    return "--" + g->info() + "--"; 
}

// todo : out CHANGED TO cout, td. CHANGED TO b->
void TextDisplay::printBoard(shared_ptr<Board> b) const {
    cout << printSpaces(35); 
    cout << printCriteria(b->getCriteria()[0]) << b->getGoals()[0] << printCriteria(b->getCriteria()[1]) << endl; 

    cout << printSpaces(35); 
    cout << printTileTop(1, 1) << endl; 

    cout << printSpaces(33); 
    cout << b->getGoals()[1] << printTileIndex(0) << b->getGoals()[2] << endl; 

    cout << printSpaces(33); 
    cout << printTileResource(0) << endl; 

    cout << printSpaces(20); 
    cout << printCriteria(b->getCriteria()[2]) + printHorizontalGoal(b->getGoals()[3]) + printCriteria(b->getCriteria()[3]) + printTileValue(0) 
        + printCriteria(b->getCriteria()[4]) + printHorizontalGoal(b->getGoals()[4]) + printCriteria(b->getCriteria()[5]) << endl; 

    cout << printSpaces(20); 
    cout << printTileTop(1, 0) + printGoose(0) + printTileTop(0, 1) << endl; 

    cout << printSpaces(18); 
    // cout << td.goals[5] + td.printTileIndex(1) + td.goals[6] + printSpaces(12) + td.goals[7] 
    //     + td.printTileIndex(2) + td.goals[8] << endl; 

    // cout << printSpaces(18);
    // cout << td.printTileResource(1) + printTileBottom(0, 0) + td.printTileResource(2) << endl;

    // cout << printSpaces(5);
    // cout << printCriteria(b->getCriteria()[6) + printHorizontalGoal(b->getGoals()[9) + printCriteria(b->getCriteria()[7)
    //     + td.printTileValue(1) + printCriteria(b->getCriteria()[8) + printHorizontalGoal(b->getGoals()[10)
    //     + printCriteria(b->getCriteria()[9) + td.printTileValue(2) + printCriteria(b->getCriteria()[10)
    //     + printHorizontalGoal(b->getGoals()[11) + printCriteria(b->getCriteria()[11) << endl;

    // cout << printSpaces(5);
    // cout << printTileTop(1, 0) + td.printGoose(1) + printTileTop(0, 0)
    //     + td.printGoose(2) + printTileTop(0, 1) << endl;
    
    // cout << printSpaces(3);
    // cout << td.goals[12] + td.printTileIndex(3) + td.goals[13] + printSpaces(12)
    //     + td.goals[14] + td.printTileIndex(4) + td.goals[15] + printSpaces(12)
    //     + td.goals[16] + td.printTileIndex(5) + td.goals[17] << endl;

    // cout << printSpaces(3);
    // cout << td.printTileResource(3) + printTileBottom(0, 0) + td.printTileResource(4)
    //     + printTileBottom(0, 0) + td.printTileResource(5) << endl;

    // cout << " " + printCriteria(b->getCriteria()[12) + td.printTileValue(3) + printCriteria(b->getCriteria()[13)
    //     + printHorizontalGoal(b->getGoals()[18) + printCriteria(b->getCriteria()[14) + td.printTileValue(4)
    //     + printCriteria(b->getCriteria()[15) + printHorizontalGoal(b->getGoals()[19) + printCriteria(b->getCriteria()[16)
    //     + td.printTileValue(5) + printCriteria(b->getCriteria()[17) << endl;

    // cout << printSpaces(3);
    // cout << td.printGoose(3) + printTileTop(0, 0) + td.printGoose(4)
    //     +  printTileTop(0, 0) + td.printGoose(5) << endl;

    // cout << printSpaces(3);
    // cout << td.goals[20] + printSpaces(12) + td.goals[21] + td.printTileIndex(6)
    //     + td.goals[22] + printSpaces(12) + td.goals[23] + td.printTileIndex(7)
    //     + td.goals[24] + printSpaces(12) + td.goals[25] << endl;

    // cout << printSpaces(5);
    // cout << printTileBottom(1, 0) + td.printTileResource(6) + printTileBottom(0, 0)
    //     + td.printTileResource(7) + printTileBottom(0, 1) << endl;

    // cout << printSpaces(5);
    // cout << printCriteria(b->getCriteria()[18) + printHorizontalGoal(b->getGoals()[26) + printCriteria(b->getCriteria()[19)
    //     + td.printTileValue(6) + printCriteria(b->getCriteria()[20) + printHorizontalGoal(b->getGoals()[27)
    //     + printCriteria(b->getCriteria()[21) + td.printTileValue(7) + printCriteria(b->getCriteria()[22)
    //     + printHorizontalGoal(b->getGoals()[28) + printCriteria(b->getCriteria()[23) << endl;

    // cout << printSpaces(5);
    // cout << printTileTop(1, 0) + td.printGoose(6) + printTileTop(0, 0)
    //     + td.printGoose(7) + printTileTop(0, 1) << endl;

    // cout << printSpaces(3);
    // cout << td.goals[29] + td.printTileIndex(8) + td.goals[30] + printSpaces(12)
    //     + td.goals[31] + td.printTileIndex(9) + td.goals[32] + printSpaces(12)
    //     + td.goals[33] + td.printTileIndex(10) + td.goals[34] << endl;

    // cout << printSpaces(3);
    // cout << td.printTileResource(8) + printTileBottom(0, 0) + td.printTileResource(9)
    //     + printTileBottom(0, 0) + td.printTileResource(10) << endl;

    // cout << " " + printCriteria(b->getCriteria()[24) + td.printTileValue(8) + printCriteria(b->getCriteria()[25)
    //     + printHorizontalGoal(b->getGoals()[35) + printCriteria(b->getCriteria()[26) + td.printTileValue(9)
    //     + printCriteria(b->getCriteria()[27) + printHorizontalGoal(b->getGoals()[36) + printCriteria(b->getCriteria()[28)
    //     + td.printTileValue(10) + printCriteria(b->getCriteria()[29) << endl;

    // cout << printSpaces(3);
    // cout << td.printGoose(8) + printTileTop(0, 0) + td.printGoose(9)
    //     +  printTileTop(0, 0) + td.printGoose(10) << endl;

    // cout << printSpaces(3);
    // cout << td.goals[37] + printSpaces(12) + td.goals[38] + td.printTileIndex(11)
    //     + td.goals[39] + printSpaces(12) + td.goals[40] + td.printTileIndex(12)
    //     + td.goals[41] + printSpaces(12) + td.goals[42] << endl;

    // cout << printSpaces(5);
    // cout << printTileBottom(1, 0) + td.printTileResource(11) + printTileBottom(0, 0)
    //     + td.printTileResource(12) + printTileBottom(0, 1) << endl;

    // cout << printSpaces(5);
    // cout << printCriteria(b->getCriteria()[30) + printHorizontalGoal(b->getGoals()[43) + printCriteria(b->getCriteria()[31)
    //     + td.printTileValue(11) + printCriteria(b->getCriteria()[32) + printHorizontalGoal(b->getGoals()[44)
    //     + printCriteria(b->getCriteria()[33) + td.printTileValue(12) + printCriteria(b->getCriteria()[34)
    //     + printHorizontalGoal(b->getGoals()[45) + printCriteria(b->getCriteria()[35) << endl;

    // cout << printSpaces(5);
    // cout << printTileTop(1, 0) + td.printGoose(11) + printTileTop(0, 0)
    //     + td.printGoose(12) + printTileTop(0, 1) << endl;

    // cout << printSpaces(3);
    // cout << td.goals[46] + td.printTileIndex(13) + td.goals[47] + printSpaces(12)
    //     + td.goals[48] + td.printTileIndex(14) + td.goals[49] + printSpaces(12)
    //     + td.goals[50] + td.printTileIndex(15) + td.goals[51] << endl;

    // cout << printSpaces(3);
    // cout << td.printTileResource(13) + printTileBottom(0, 0) + td.printTileResource(14)
    //     + printTileBottom(0, 0) + td.printTileResource(15) << endl;

    // cout << " " + printCriteria(b->getCriteria()[36) + td.printTileValue(13) + printCriteria(b->getCriteria()[37)
    //     + printHorizontalGoal(b->getGoals()[52) + printCriteria(b->getCriteria()[38) + td.printTileValue(14)
    //     + printCriteria(b->getCriteria()[39) + printHorizontalGoal(b->getGoals()[53) + printCriteria(b->getCriteria()[40)
    //     + td.printTileValue(15) + printCriteria(b->getCriteria()[41) << endl;

    // cout << printSpaces(3);
    // cout << td.printGoose(13) + printTileTop(0, 0) + td.printGoose(14)
    //     +  printTileTop(0, 0) + td.printGoose(15) << endl;

    // cout << printSpaces(3);
    // cout << td.goals[54] + printSpaces(12) + td.goals[55] + td.printTileIndex(16)
    //     + td.goals[56] + printSpaces(12) + td.goals[57] + td.printTileIndex(17)
    //     + td.goals[58] + printSpaces(12) + td.goals[59] << endl;

    // cout << printSpaces(5);
    // cout << printTileBottom(1, 0) + td.printTileResource(16) + printTileBottom(0, 0)
    //     + td.printTileResource(17) + printTileBottom(0, 1) << endl;

    // cout << printSpaces(5);
    // cout << printCriteria(b->getCriteria()[42) + printHorizontalGoal(b->getGoals()[60) + printCriteria(b->getCriteria()[43)
    //     + td.printTileValue(16) + printCriteria(b->getCriteria()[44) + printHorizontalGoal(b->getGoals()[61)
    //     + printCriteria(b->getCriteria()[45) + td.printTileValue(17) + printCriteria(b->getCriteria()[46)
    //     + printHorizontalGoal(b->getGoals()[62) + printCriteria(b->getCriteria()[47) << endl;

    // cout << printSpaces(18);
    // cout << td.printGoose(16) + printTileTop(0, 0) + td.printGoose(17) << endl;

    // cout << printSpaces(18);
    // cout << td.goals[63] + printSpaces(12) + td.goals[64] + td.printTileIndex(18)
    //     + td.goals[65] + printSpaces(12) + td.goals[66] << endl;

    // cout << printSpaces(20);
    // cout << printTileBottom(1, 0) + td.printTileResource(18) + printTileBottom(0, 1);
    // cout << endl;

    // cout << printSpaces(20);
    // cout << printCriteria(b->getCriteria()[48]) + printHorizontalGoal(b->getGoals()[67) + printCriteria(b->getCriteria()[49])
    //     + td.printTileValue(18) + printCriteria(b->getCriteria()[50]) + printHorizontalGoal(b->getGoals()[68)
    //     + printCriteria(b->getCriteria()[51]) << endl;

    // cout << printSpaces(33);
    // cout << td.printGoose(18) << endl;

    // cout << printSpaces(33);
    // cout << td.goals[69] + printSpaces(12) + td.goals[70] << endl;

    // cout << printSpaces(35);
    // cout << printTileBottom(1,1) << endl;

    // cout << printSpaces(35);
    // cout << printCriteria(b->getCriteria()[52]) + printHorizontalGoal(b->getGoals()[71) + printCriteria(b->getCriteria()[53]);
    // cout << endl;

    // return out; 
}


