#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
// EXCEPTIONS.H: A series of in-game exceptions as defined by three categories:
// (a) File I/O Errors, (b) Invalid User Input, and (c) Insufficient Conditions.

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

class InsufficientResourcesException : public logic_error {
public:
    explicit InsufficientResourcesException(const string &note);
};

class InvalidCriterionImprovementException : public logic_error {
public:
    explicit InvalidCriterionImprovementException(const string &note);
};

class InvalidGeesePlacementException : public logic_error {
public:
    explicit InvalidGeesePlacementException(const string &note);
};

#endif