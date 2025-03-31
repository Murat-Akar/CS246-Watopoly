#ifndef ACTIONSQUARE_H
#define ACTIONSQUARE_H

#include "Square.h"
#include "Player.h"
#include "PropertyData.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class ActionSquare : public Square {
public:
    ActionSquare(const string &name, int posn);
    virtual bool landOn(Player *p) override;
    virtual void applyAction(Player *p) = 0;
};

#endif
