#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

using namespace std;

// (a) File I/O Errors
class FileNotFoundException : public runtime_error {
    public:
        explicit FileNotFoundException(const string& note);
};

class FileFormatException : public runtime_error {
    public:
        explicit FileFormatException(const string& note);
};

class FileWriteException : public runtime_error {
    public:
        explicit FileWriteException(const string& note);
};

// (b) Invalid User Input
class InvalidCommandException : public invalid_argument {
    public:
        explicit InvalidCommandException(const string& note);
};

class InvalidInputException : public invalid_argument {
    public:
        explicit InvalidInputException(const string& note);
};

class OutOfRangeInputException : public out_of_range {
    public:
        explicit OutOfRangeInputException(const string& note);
};

// (c) Insufficient Conditions
class AlreadyOwnedException : public logic_error {
public:
    explicit AlreadyOwnedException(const string &note);
};

class NonAdjacentPlacementException : public logic_error {
public:
    explicit NonAdjacentPlacementException(const string &note);
};

class AdjacentPlacementException : public logic_error {
public:
    explicit AdjacentPlacementException(const string &note);
};

class InsufficientResourcesException : public logic_error {
public:
    explicit InsufficientResourcesException(const string &note);
};

class InvalidCriteriaImprovementException : public logic_error {
public:
    explicit InvalidCriteriaImprovementException(const string &note);
};

class InvalidGeesePlacementException : public logic_error {
public:
    explicit InvalidGeesePlacementException(const string &note);
    // explicit InvalidGeesePlacementException(const char *note);
};

// (d) Miscellaneous
class ResourceTypeConversionException : public out_of_range {
public:
    explicit ResourceTypeConversionException(const string &note);
};

class InvalidCommandLineException : public invalid_argument {
public:
    explicit InvalidCommandLineException(const string &note);
};

#endif