#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <memory>
using namespace std; 

class Board;
class Student;

struct GameState {
    std::vector<std::shared_ptr<Student>> &students;
    std::shared_ptr<Board> theBoard;
    shared_ptr<Student> curPlayer; 
};

#endif
