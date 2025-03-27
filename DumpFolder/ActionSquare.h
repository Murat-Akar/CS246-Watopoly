#ifndef ACTIONSQUARE_H
#define ACTIONSQUARE_H

#include "Square.h"

class ActionSquare : public Square {
public:
    ActionSquare(const string &n, int i);
    bool landOn(Player *p) override;
};

#endif // ACTIONSQUARE_H
