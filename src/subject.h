#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include "gameEvent.h"
#include "gameState.h"
#include "trade.h"

using namespace std;

class Observer; 
class Gameplay; 

class Subject {
protected:
    std::vector<shared_ptr<Observer>> observers;
public:
    void attach(shared_ptr<Observer> o);
    void detach(shared_ptr<Observer> o);
    void notifyObservers(GameEvent ge);
    void notifyObservers(GameEvent ge, Trade t);
    virtual GameState getState() = 0;
    virtual ~Subject() = default;
};

#endif
