#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>
#include <algorithm>

class Observer; 

class Subject {
    std::vector<Observer *> observers;

public:
    void attach( Observer* o );
    void detach( Observer* o );
    virtual void notifyObservers() = 0; 
    virtual ~Subject() = default;
};

#endif
