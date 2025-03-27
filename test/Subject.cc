#include "Subject.h"

void Subject::attach(Observer* o) {
    observers.push_back(o);
}

void Subject::detach(Observer* o) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            return;
        }
    }
}

void Subject::notifyObservers() const {
    for (auto o : observers) {
        o->notify();
    }
}
