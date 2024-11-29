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
    } else if (ge == GameEvent::PlayerCriteria) {
        cout << gp->getState().students.criteria();
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
       if (gp->getLastErrorMessage() != "") {
            cout << gp->getLastErrorMessage(); 
        }
    } else if (ge == GameEvent::Complete) {
        if (gp->getLastErrorMessage() != "") {
            cout << gp->getLastErrorMessage(); 
        }
    } else if (ge == GameEvent::Improve) {
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
    return "/" + printSpaces(5) + resources[index].resource + printSpaces(9-resources[index].resource.length()) + "\\";
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
    return printSpaces(6) + output + printSpaces(6); 
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

string TextDisplay::printCriteria(shared_ptr<Criteria> c) const { 
    return "|" + c->info() + "|"; 
}

string TextDisplay::printHorizontalGoal(shared_ptr<Goal> g) const {
    return "--" + g->info() + "--"; 
}

// todo : out CHANGED TO cout, td. CHANGED TO b->
void TextDisplay::printBoard(shared_ptr<Board> b) const {
    cout << printSpaces(35); 
    cout << printCriteria(b->getCriteria()[0]) << printHorizontalGoal(b->getGoals()[0]) << printCriteria(b->getCriteria()[1]) << endl; 

    cout << printSpaces(35); 
    cout << printTileTop(1, 1) << endl; 

    cout << printSpaces(33); 
    cout << b->getGoals()[1] << printTileIndex(0) << b->getGoals()[2] << endl; 

    cout << printSpaces(33); 
    cout << printTileResource(0) << endl; 

    cout << printSpaces(20); 
    cout << printCriteria(b->getCriteria()[2]) << printHorizontalGoal(b->getGoals()[3]) << printCriteria(b->getCriteria()[3]) << printTileValue(0) 
        << printCriteria(b->getCriteria()[4]) << printHorizontalGoal(b->getGoals()[4]) << printCriteria(b->getCriteria()[5]) << endl; 

    cout << printSpaces(20); 
    cout << printTileTop(1, 0) << printGoose(0) << printTileTop(0, 1) << endl; 

    cout << printSpaces(18); 
    cout << b->getGoals()[5] << printTileIndex(1) << b->getGoals()[6] << printSpaces(12) << b->getGoals()[7] 
        << printTileIndex(2) << b->getGoals()[8] << endl; 

    cout << printSpaces(18);
    cout << printTileResource(1) << printTileBottom(0, 0) << printTileResource(2) << endl;

    cout << printSpaces(5);
    cout << printCriteria(b->getCriteria()[6]) << printHorizontalGoal(b->getGoals()[9]) << printCriteria(b->getCriteria()[7])
        << printTileValue(1) << printCriteria(b->getCriteria()[8]) << printHorizontalGoal(b->getGoals()[10])
        << printCriteria(b->getCriteria()[9]) << printTileValue(2) << printCriteria(b->getCriteria()[10])
        << printHorizontalGoal(b->getGoals()[11]) << printCriteria(b->getCriteria()[11]) << endl;

    cout << printSpaces(5);
    cout << printTileTop(1, 0) << printGoose(1) << printTileTop(0, 0)
        + printGoose(2) << printTileTop(0, 1) << endl;
    
    cout << printSpaces(3);
    cout << b->getGoals()[12] << printTileIndex(3) << b->getGoals()[13] << printSpaces(12)
        << b->getGoals()[14] << printTileIndex(4) << b->getGoals()[15] << printSpaces(12)
        << b->getGoals()[16] << printTileIndex(5) << b->getGoals()[17] << endl;

    cout << printSpaces(3);
    cout << printTileResource(3) << printTileBottom(0, 0) << printTileResource(4)
        << printTileBottom(0, 0) << printTileResource(5) << endl;

    cout << " " << printCriteria(b->getCriteria()[12]) << printTileValue(3) << printCriteria(b->getCriteria()[13])
        << printHorizontalGoal(b->getGoals()[18]) << printCriteria(b->getCriteria()[14]) << printTileValue(4)
        << printCriteria(b->getCriteria()[15]) << printHorizontalGoal(b->getGoals()[19]) << printCriteria(b->getCriteria()[16])
        << printTileValue(5) << printCriteria(b->getCriteria()[17]) << endl;

    cout << printSpaces(3);
    cout << printGoose(3) << printTileTop(0, 0) << printGoose(4)
        <<  printTileTop(0, 0) << printGoose(5) << endl;

// line 15
    cout << printSpaces(3);
    cout << b->getGoals()[20] << printSpaces(12) << b->getGoals()[21] << printTileIndex(6)
        << b->getGoals()[22] << printSpaces(12) << b->getGoals()[23] << printTileIndex(7)
        << b->getGoals()[24] << printSpaces(12) << b->getGoals()[25] << endl;

    cout << printSpaces(5);
    cout << printTileBottom(1, 0) << printTileResource(6) << printTileBottom(0, 0)
        << printTileResource(7) << printTileBottom(0, 1) << endl;

    cout << printSpaces(5);
    cout << printCriteria(b->getCriteria()[18]) << printHorizontalGoal(b->getGoals()[26]) << printCriteria(b->getCriteria()[19])
        << printTileValue(6) << printCriteria(b->getCriteria()[20]) << printHorizontalGoal(b->getGoals()[27])
        << printCriteria(b->getCriteria()[21]) << printTileValue(7) << printCriteria(b->getCriteria()[22])
        << printHorizontalGoal(b->getGoals()[28]) << printCriteria(b->getCriteria()[23]) << endl;

    cout << printSpaces(5);
    cout << printTileTop(1, 0) << printGoose(6) << printTileTop(0, 0)
        << printGoose(7) << printTileTop(0, 1) << endl;

    cout << printSpaces(3);
    cout << b->getGoals()[29] << printTileIndex(8) << b->getGoals()[30] << printSpaces(12)
        << b->getGoals()[31] << printTileIndex(9) << b->getGoals()[32] << printSpaces(12)
        << b->getGoals()[33] << printTileIndex(10) << b->getGoals()[34] << endl;
// line 20
    cout << printSpaces(3);
    cout << printTileResource(8) << printTileBottom(0, 0) << printTileResource(9)
        << printTileBottom(0, 0) << printTileResource(10) << endl;

    cout << " " << printCriteria(b->getCriteria()[24]) << printTileValue(8) << printCriteria(b->getCriteria()[25])
        << printHorizontalGoal(b->getGoals()[35]) << printCriteria(b->getCriteria()[26]) << printTileValue(9)
        << printCriteria(b->getCriteria()[27]) << printHorizontalGoal(b->getGoals()[36]) << printCriteria(b->getCriteria()[28])
        << printTileValue(10) << printCriteria(b->getCriteria()[29]) << endl;

    cout << printSpaces(3);
    cout << printGoose(8) << printTileTop(0, 0) << printGoose(9)
        <<  printTileTop(0, 0) << printGoose(10) << endl;

    cout << printSpaces(3);
    cout << b->getGoals()[37] << printSpaces(12) << b->getGoals()[38] << printTileIndex(11)
        << b->getGoals()[39] << printSpaces(12) << b->getGoals()[40] << printTileIndex(12)
        << b->getGoals()[41] << printSpaces(12) << b->getGoals()[42] << endl;

    cout << printSpaces(5);
    cout << printTileBottom(1, 0) << printTileResource(11) << printTileBottom(0, 0)
        << printTileResource(12) << printTileBottom(0, 1) << endl;

    cout << printSpaces(5);
    cout << printCriteria(b->getCriteria()[30]) << printHorizontalGoal(b->getGoals()[43]) << printCriteria(b->getCriteria()[31])
        << printTileValue(11) << printCriteria(b->getCriteria()[32]) << printHorizontalGoal(b->getGoals()[44])
        << printCriteria(b->getCriteria()[33]) << printTileValue(12) << printCriteria(b->getCriteria()[34])
        << printHorizontalGoal(b->getGoals()[45]) << printCriteria(b->getCriteria()[35]) << endl;

    cout << printSpaces(5);
    cout << printTileTop(1, 0) << printGoose(11) << printTileTop(0, 0)
        << printGoose(12) << printTileTop(0, 1) << endl;

    cout << printSpaces(3);
    cout << b->getGoals()[46] << printTileIndex(13) << b->getGoals()[47] << printSpaces(12)
        << b->getGoals()[48] << printTileIndex(14) << b->getGoals()[49] << printSpaces(12)
        << b->getGoals()[50] << printTileIndex(15) << b->getGoals()[51] << endl;

    cout << printSpaces(3);
    cout << printTileResource(13) << printTileBottom(0, 0) << printTileResource(14)
        << printTileBottom(0, 0) << printTileResource(15) << endl;

    cout << " " << printCriteria(b->getCriteria()[36]) << printTileValue(13) << printCriteria(b->getCriteria()[37])
        << printHorizontalGoal(b->getGoals()[52]) << printCriteria(b->getCriteria()[38]) << printTileValue(14)
        << printCriteria(b->getCriteria()[39]) << printHorizontalGoal(b->getGoals()[53]) << printCriteria(b->getCriteria()[40])
        << printTileValue(15) << printCriteria(b->getCriteria()[41]) << endl;
// tile 30
    cout << printSpaces(3);
    cout << printGoose(13) << printTileTop(0, 0) << printGoose(14)
        <<  printTileTop(0, 0) << printGoose(15) << endl;

    cout << printSpaces(3);
    cout << b->getGoals()[54] << printSpaces(12) << b->getGoals()[55] << printTileIndex(16)
        << b->getGoals()[56] << printSpaces(12) << b->getGoals()[57] << printTileIndex(17)
        << b->getGoals()[58] << printSpaces(12) << b->getGoals()[59] << endl;

    cout << printSpaces(5);
    cout << printTileBottom(1, 0) << printTileResource(16) << printTileBottom(0, 0)
        << printTileResource(17) << printTileBottom(0, 1) << endl;

    cout << printSpaces(5);
    cout << printCriteria(b->getCriteria()[42]) << printHorizontalGoal(b->getGoals()[60]) << printCriteria(b->getCriteria()[43])
        << printTileValue(16) << printCriteria(b->getCriteria()[44]) << printHorizontalGoal(b->getGoals()[61])
        << printCriteria(b->getCriteria()[45]) << printTileValue(17) << printCriteria(b->getCriteria()[46])
        << printHorizontalGoal(b->getGoals()[62]) << printCriteria(b->getCriteria()[47]) << endl;

    cout << printSpaces(18);
    cout << printGoose(16) << printTileTop(0, 0) << printGoose(17) << endl;

    cout << printSpaces(18);
    cout << b->getGoals()[63] << printSpaces(12) << b->getGoals()[64] << printTileIndex(18)
        << b->getGoals()[65] << printSpaces(12) << b->getGoals()[66] << endl;

    cout << printSpaces(20);
    cout << printTileBottom(1, 0) << printTileResource(18) << printTileBottom(0, 1);
    cout << endl;

    cout << printSpaces(20);
    cout << printCriteria(b->getCriteria()[48]) << printHorizontalGoal(b->getGoals()[67]) << printCriteria(b->getCriteria()[49])
        << printTileValue(18) << printCriteria(b->getCriteria()[50]) << printHorizontalGoal(b->getGoals()[68])
        << printCriteria(b->getCriteria()[51]) << endl;

    cout << printSpaces(33);
    cout << printGoose(18) << endl;

    cout << printSpaces(33);
    cout << b->getGoals()[69] << printSpaces(12) << b->getGoals()[70] << endl;
// line 40
    cout << printSpaces(35);
    cout << printTileBottom(1,1) << endl;

    cout << printSpaces(35);
    cout << printCriteria(b->getCriteria()[52]) << printHorizontalGoal(b->getGoals()[71]) << printCriteria(b->getCriteria()[53]);
    cout << endl;

}


