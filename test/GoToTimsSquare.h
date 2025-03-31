#ifndef GOTO_TIMS_SQUARE_H
#define GOTO_TIMS_SQUARE_H

#include "ActionSquare.h"

class GoToTimsSquare : public ActionSquare {
public:
    GoToTimsSquare(int posn);
    virtual void applyAction(Player *p) override;
};

#endif // GOTO_TIMS_SQUARE_H
