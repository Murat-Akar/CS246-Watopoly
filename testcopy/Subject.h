#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
using namespace std;

class Subject {
protected:
    vector<Observer*> observers;
public:
    void attach(Observer* o);
    void detach(Observer* o);
    void notifyObservers() const;
    virtual ~Subject() = default;
};

#endif // SUBJECT_H
