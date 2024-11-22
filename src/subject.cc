#include "subject.h"
#include <algorithm>

void Subject::attach(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Subject::detach(std::shared_ptr<Observer> observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify() const {
    for (const auto& observer : observers) {
        observer->update();
    }
}Ï
