#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include <map>
#include <string>

enum class ResourceType { CAFFEINE, LAB, LECTURE, STUDY, TUTORIAL, NETFLIX };

const std::map<ResourceType, std::string> RESOURCE_TYPE_STRINGS = {
    {ResourceType::CAFFEINE, "CAFFEINE"},
    {ResourceType::LAB, "LAB"},
    {ResourceType::LECTURE, "LECTURE"},
    {ResourceType::STUDY, "STUDY"},
    {ResourceType::TUTORIAL, "TUTORIAL"},
    {ResourceType::NETFLIX, "NETFLIX"}
};

enum class Colour { BLUE, RED, ORANGE, YELLOW };

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int NUM_TILES = 19;
const int NOT_IN_PLAY = -1;

const std::vector<std::vector<int>> TILE_ROWS = {
    {0, 1, 2},
    {3, 4, 5, 6},
    {7, 8, 9, 10, 11},
    {12, 13, 14, 15},
    {16, 17, 18}
};

#endif

