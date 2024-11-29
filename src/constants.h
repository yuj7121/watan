#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include <map>
#include <string>

enum class CompletionType { NONE, ASSIGNMENT, MIDTERM, EXAM }; // move to goal file

enum class ResourceType { CAFFEINE, LAB, LECTURE, STUDY, TUTORIAL, NETFLIX, ERROR}; // move to tile file

std::string resourceTypeToString(ResourceType r); // move under the tile class file (as a static class maybe)
ResourceType stringToResourceType(const std::string& str);
ResourceType intToResourceType(const int i);

enum class Colour { BLUE, RED, ORANGE, YELLOW };

std::string colourToString(Colour c);

Colour stringToColour(const std::string& str);


extern const std::map<ResourceType, std::string> RESOURCE_TYPE_STRINGS;
extern const std::map<Colour, std::string> COLOUR_TO_STRING;

// extern const int WINDOW_WIDTH;
// extern const int WINDOW_HEIGHT;

// extern const int NUM_RESOURCE_TYPES;
// extern const int NUM_STUDENTS;
// extern const int NUM_TILES;
// extern const int NUM_GOALS;
// extern const int NUM_CRITERION;
// extern const int NOT_IN_PLAY;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define NUM_RESOURCE_TYPES 6
#define NUM_STUDENTS 4
#define NUM_TILES 19
#define NUM_GOALS 72
#define NUM_CRITERION 5
#define NOT_IN_PLAY -1

extern const std::vector<std::vector<int>> TILE_ROWS;

extern const std::vector<std::vector<int>> CRITERION_PER_TILE;

extern const std::vector<std::vector<int>> GOAL_PER_TILE;

extern const std::vector<std::vector<int>> ADJ_GOAL_PER_CRITERIA;

extern const std::vector<std::vector<int>> ADJ_CRITERIA_PER_GOAL;


#endif

