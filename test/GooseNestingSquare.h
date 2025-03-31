#ifndef GOOSE_NESTING_SQUARE_H
#define GOOSE_NESTING_SQUARE_H

#include "ActionSquare.h"

class GooseNestingSquare : public ActionSquare {
private:
    int collectAmount;
public:
    GooseNestingSquare(int posn, int collectAmount = 0);
    virtual void applyAction(Player *p) override;
};

#endif
