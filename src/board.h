#ifndef BOARD_H
#define BOARD_H
// BOARD.H: The Board in which the game is played on, storing data about its Tiles.

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

enum class ResourceType { CAFFEINE, LAB, LECTURE, STUDY, TUTORIAL, NETFLIX };
enum class Colour { BLUE, RED, ORANGE, YELLOW };

class Tile;
class Goal;
class Criteria;

class Board {
    std::vector<std::unique_ptr<Tile>> tiles;
    std::vector<std::unique_ptr<Goal>> goals;
    std::vector<std::unique_ptr<Criteria>> criterion;
    int geesePosition;

    public:
        Board();

        void setupBoard(const std::string &fileName);

        void printBoard() const;
        void printStudents() const;
        void printCriterion(int studentIndex) const;

        const std::vector<std::unique_ptr<Tile>>& getTiles() const;
        int getGeese() const;

        void tileRolled(int roll);

        void buyGoal(int student, int index);
        void buyCriteria(int student, int index);
        void improveCriteria(int student, int index);

        void moveGeese(int index);
        void trade(int offeringStudent, int receivingStudent, ResourceType type);
};

#endif