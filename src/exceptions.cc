#include "exceptions.h"

using namespace std;

// (a) File I/O Errors
FileNotFoundException::FileNotFoundException(const string& note)
: runtime_error("EXCEPTION: File wasn't found: " + note) {}

FileFormatException::FileFormatException(const string& note)
: runtime_error("EXCEPTION: Error in file formatting: " + note) {}

FileWriteException::FileWriteException(const string& note)
: runtime_error("EXCEPTION: Error writing to file: " + note) {}

// (b) Invalid User Input
InvalidInputException::InvalidInputException(const string& note)
: invalid_argument("Invalid input detected: " + note) {}

InvalidCommandException::InvalidCommandException(const string& note)
: invalid_argument("" + note) {}

OutOfRangeInputException::OutOfRangeInputException(const string& note)
: out_of_range("EXCEPTION: Input is out of range: " + note) {}

// (c) Insufficient Conditions
AlreadyOwnedException::AlreadyOwnedException(const string& note)
: logic_error("EXCEPTION: Criteria/Goal is already owned: " + note) {}

NonAdjacentPlacementException::NonAdjacentPlacementException(const string& note)
: logic_error("EXCEPTION: Goal is not adjacent to one owned by player: " + note) {}

AdjacentPlacementException::AdjacentPlacementException(const string& note)
: logic_error("EXCEPTION: An adjacent criterion is completed: " + note) {}

InsufficientResourcesException::InsufficientResourcesException(const string& note)
: logic_error("EXCEPTION: Resources needed for Criteria/Goal are insufficient: " + note) {}

InvalidCriteriaImprovementException::InvalidCriteriaImprovementException(const string& note)
: logic_error("EXCEPTION: Criteria cannot be improved: " + note) {}

// (d) Miscellaneous
ResourceTypeConversionException::ResourceTypeConversionException(const string& note)
: out_of_range("EXCEPTION: Trouble converting ResourceType to string: " + note) {}

InvalidCommandLineException::InvalidCommandLineException(const string& note)
: invalid_argument("EXCEPTION: Invalid command line input: " + note) {}

InvalidGeesePlacementException::InvalidGeesePlacementException(const string&note)
: logic_error("EXCEPTION: Invalid geesse placement: " + note) {}


