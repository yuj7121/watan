#ifndef BOARD_H
#define BOARD_H

#include "boardSetup.h"

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

enum class ResourceType { CAFFEINE, LAB, LECTURE, STUDY, TUTORIAL, NETFLIX };

class Tile;
class Goal;
class Criteria;

class Board {
    std::vector<std::shared_ptr<Tile>> tiles;
    std::vector<std::shared_ptr<Goal>> goals;
    std::vector<std::shared_ptr<Criteria>> criterion;
    int geesePosition;
    friend class BoardSetup;

    public:
        Board();

        void printBoard() const;
        void printStudents() const;
        void printCriterion(int studentIndex) const;

        const std::vector<std::shared_ptr<Tile>>& getTiles() const;
        int getGeese() const;

        void tileRolled(int roll);

        void buyGoal(int student, int index);
        void buyCriteria(int student, int index);
        void improveCriteria(int student, int index);

        void moveGeese(int index);
        void trade(int offeringStudent, int receivingStudent, ResourceType type);
};

#endif