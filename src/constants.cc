#include "constants.h"

std::string resourceTypeToString(ResourceType r) { // move under the tile class file (as a static class maybe)
    switch (r) {
        case ResourceType::CAFFEINE: return "CAFFEINE";
        case ResourceType::LAB: return "LAB";
        case ResourceType::LECTURE: return "LECTURE";
        case ResourceType::STUDY: return "STUDY";
        case ResourceType::TUTORIAL: return "TUTORIAL";
        case ResourceType::NETFLIX: return "NETFLIX";
    }
    return "Error";
}

int resourceTypeToInt(ResourceType r) {
    switch (r) {
        case ResourceType::CAFFEINE: return 0;
        case ResourceType::LAB: return 1;
        case ResourceType::LECTURE: return 2;
        case ResourceType::STUDY: return 3;
        case ResourceType::TUTORIAL: return 4;
        case ResourceType::NETFLIX: return 5;
        case ResourceType::ERROR: return -1;
    }
    return -1;

}

ResourceType stringToResourceType(const std::string& str) {
    if (str == "CAFFEINE") return ResourceType::CAFFEINE;
    if (str == "LAB") return ResourceType::LAB;
    if (str == "LECTURE") return ResourceType::LECTURE;
    if (str == "STUDY") return ResourceType::STUDY;
    if (str == "TUTORIAL") return ResourceType::TUTORIAL;
    if (str == "NETFLIX") return ResourceType::NETFLIX;
    return ResourceType::NETFLIX;

}

ResourceType intToResourceType(const int i) {
    if (i == 0) return ResourceType::CAFFEINE;
    if (i == 1) return ResourceType::LAB;
    if (i == 2) return ResourceType::LECTURE;
    if (i == 3) return ResourceType::STUDY;
    if (i == 4) return ResourceType::TUTORIAL;
    if (i == 5) return ResourceType::NETFLIX;
    return ResourceType::NETFLIX;
}

const std::map<ResourceType, std::string> RESOURCE_TYPE_STRINGS = {
    {ResourceType::CAFFEINE, "CAFFEINE"},
    {ResourceType::LAB, "LAB"},
    {ResourceType::LECTURE, "LECTURE"},
    {ResourceType::STUDY, "STUDY"},
    {ResourceType::TUTORIAL, "TUTORIAL"},
    {ResourceType::NETFLIX, "NETFLIX"}
};

std::string colourToString(Colour c) {
    switch (c) {
        case Colour::BLUE: return "Blue";
        case Colour::RED: return "Red";
        case Colour::ORANGE: return "Orange";
        case Colour::YELLOW: return "Yellow";
    }
    return "Error";
}

Colour stringToColour(const std::string& str) {
    if (str == "Blue") return Colour::BLUE;
    if (str == "Red") return Colour::RED;
    if (str == "Orange") return Colour::ORANGE;
    if (str == "Yellow") return Colour::YELLOW;
    return Colour::YELLOW;
}

Colour intToColour(const int i) {
    if (i == 0) return Colour::BLUE;
    if (i == 1) return Colour::RED;
    if (i == 2) return Colour::ORANGE;
    if (i == 3) return Colour::YELLOW;
    return Colour::YELLOW;
}

const std::map<Colour, std::string> COLOUR_TO_STRING = {
    {Colour::BLUE, "Blue"},
    {Colour::RED, "Red"},
    {Colour::ORANGE, "Orange"},
    {Colour::YELLOW, "Yellow"}
};

// const int WINDOW_WIDTH = 800;
// const int WINDOW_HEIGHT = 600;

// const int NUM_RESOURCE_TYPES = 6;
// const int NUM_STUDENTS = 4;
// const int NUM_TILES = 19;
// const int NUM_GOALS = 72;
// const int NUM_CRITERION = 54;
// const int NOT_IN_PLAY = -1;

const std::vector<std::vector<int>> TILE_ROWS = {
    {0, 1, 2},
    {3, 4, 5, 6},
    {7, 8, 9, 10, 11},
    {12, 13, 14, 15},
    {16, 17, 18}
};

const std::vector<std::vector<int>> CRITERION_PER_TILE {
    {0, 1, 3, 4, 8, 9}, {2, 3, 7, 8, 13, 14}, {4, 5, 9, 10, 15, 16},
    {6, 7, 12, 13, 18, 19}, {8, 9, 14, 15, 20, 21}, {10, 11, 16, 17, 22, 23},
    {13, 14, 19, 20, 25, 26}, {15, 16, 21, 22, 27, 28}, {18, 19, 24, 25, 30, 31},
    {20, 21, 26, 27, 32, 33}, {22, 23, 28, 29, 34, 35}, {25, 26, 31, 32, 37, 38},
    {27, 28, 33, 34, 39, 40}, {30, 31, 36, 37, 42, 43}, {32, 33, 38, 39, 44, 35},
    {34, 35, 40, 41, 46, 47}, {37, 38, 43, 44, 48, 49} , {39, 40, 45, 46, 50, 51},
    {44, 45, 49, 50, 52, 53} };

const std::vector<std::vector<int>> GOAL_PER_TILE {
    {0, 1}, {0, 2}, {3, 5}, {1, 3, 6}, {2, 4, 7}, {4, 8}, {9, 12}, {5, 9, 13},
    {6, 10, 14}, {7, 10, 15}, {8, 11, 16}, {11, 17}, {12, 20}, {13, 18, 21},
    {14, 18, 22}, {15, 19, 23}, {16, 19, 24}, {17, 25}, {20, 26, 29},
    {21, 26, 30}, {22, 27, 31}, {23, 27, 32}, {24, 28, 33}, {25, 28, 34},
    {29, 37}, {30, 35, 38}, {31, 35, 39}, {32, 36, 40}, {33, 36, 41},
    {34, 42}, {37, 43, 46}, {38, 43, 47}, {39, 44, 48}, {40, 44, 49},
    {41, 45, 50}, {42, 45, 51}, {46, 54}, {47, 52, 55}, {48, 52, 56},
    {49, 53, 57}, {50, 53, 58}, {51, 59}, {54, 60}, {55, 60, 63}, {56, 61, 64},
    {57, 61, 65}, {58, 62, 66}, {59, 62}, {63, 67}, {64, 67, 69}, {65, 68, 70},
    {66, 68}, {69, 71}, {70, 71}
};


const std::vector<std::vector<int>> ADJ_GOAL_PER_CRITERIA {
    {0, 1}, {0, 2}, {3, 5}, {1, 3, 6}, {2, 4, 7}, {4, 8}, {9, 12}, {5, 9, 13},
    {6, 10, 14}, {7, 10, 15}, {8, 11, 16}, {11, 17}, {12, 20}, {13, 18, 21},
    {14, 18, 22}, {15, 19, 23}, {16, 19, 24}, {17, 25}, {20, 26, 29},
    {21, 26, 30}, {22, 27, 31}, {23, 27, 32}, {24, 28, 33}, {25, 28, 34},
    {29, 37}, {30, 35, 38}, {31, 35, 39}, {32, 36, 40}, {33, 36, 41},
    {34, 42}, {37, 43, 46}, {38, 43, 47}, {39, 44, 48}, {40, 44, 49},
    {41, 45, 50}, {42, 45, 51}, {46, 54}, {47, 52, 55}, {48, 52, 56},
    {49, 53, 57}, {50, 53, 58}, {51, 59}, {54, 60}, {55, 60, 63}, {56, 61, 64},
    {57, 61, 65}, {58, 62, 66}, {59, 62}, {63, 67}, {64, 67, 69}, {65, 68, 70},
    {66, 68}, {69, 71}, {70, 71}
};

const std::vector<std::vector<int>> ADJ_CRITERIA_PER_GOAL {
    {0, 1}, {0, 3}, {1, 4}, {2, 3}, {4, 5}, {2, 7}, {3, 8}, {4, 9},
    {5, 10}, {6, 7}, {8, 9}, {10, 11}, {6, 12}, {7, 13}, {8, 14},
    {9, 15}, {10, 16}, {11, 17}, {13, 14}, {15, 16}, {12, 18},
    {13, 19}, {14, 20}, {15, 21}, {16, 22}, {17, 23}, {18, 19},
    {20, 21}, {22, 23}, {18, 24}, {19, 25}, {20, 26}, {21, 27},
    {22, 28}, {23, 29}, {25, 26}, {27, 28}, {24, 30}, {25, 31},
    {26, 32}, {27, 33}, {28, 34}, {29, 35}, {30, 31}, {32, 33},
    {34, 35}, {30, 36}, {31, 37}, {32, 38}, {33, 39}, {34, 40},
    {35, 41}, {37, 38}, {39, 40}, {36, 42}, {37, 43}, {38, 44},
    {39, 45}, {40, 46}, {41, 47}, {42, 43}, {44, 45}, {46, 47},
    {43, 48}, {44, 49}, {45, 50}, {46, 51}, {48, 49}, {50, 51},
    {49, 52}, {50, 53}, {52, 53}
};

const Colour studentColours[] = {Colour::BLUE, Colour::RED, Colour::ORANGE, Colour::YELLOW};
const ResourceType studentResourceTypes[] = {ResourceType::CAFFEINE, ResourceType::LAB, 
                                        ResourceType::LECTURE, ResourceType::TUTORIAL, 
                                        ResourceType::STUDY};
const CompletionType completionTypes[] = {CompletionType::NONE, CompletionType::ASSIGNMENT, CompletionType::MIDTERM, CompletionType::EXAM};



