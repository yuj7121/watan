#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"

#include <vector>
#include <memory>
#include <algorithm>

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;

public:
    virtual ~Subject() = default;
    void attach(std::shared_ptr<Observer> observer);
    void detach(std::shared_ptr<Observer> observer);
    void notify() const;
};

#endif
