#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

enum class Colour { BLUE, RED, ORANGE, YELLOW };
enum class ResourceType { CAFFEINE, LAB, LECTURE, STUDY, TUTORIAL, NETFLIX };

//remvoe these and replace with including header files once done!!
class Tile;
class Goal;
class Criteria;

class Student {
    Colour colour;
    vector<Criteria*> criterion;
    vector<Goal*> goals;
    unoredered_map<ResourceType, int> resources;
    int victoryPotins;

  public:
    int getIndex();
    Colour getColour();
    int getVictoryPoints();
    unordered_map<String, int> getResource();
    int getColour();
    int* getCriterion();

    void addResource(ResourceType type);
    void removeResourcec(ResourceType type);
    void addGoal(int index);
    void addCriterion(int index);
    void updateCriteria(int index);
}

#endif