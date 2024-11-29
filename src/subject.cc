#include "subject.h"
#include "observer.h"
#include <iostream>
using namespace std; 

void Subject::attach(shared_ptr<Observer> o) {
    observers.push_back(o);
}

void Subject::detach(shared_ptr<Observer> o) {
    for ( auto it = observers.begin(); it != observers.end(); ++it ) {
        if ( *it == o ) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers(GameEvent ge) {
    for (auto ob : observers) {
        ob->notify(ge);
    }
}

void Subject::notifyObservers(GameEvent ge, Trade t) {
    for (auto ob : observers) {
        ob->notify(ge, t);
    }
}
