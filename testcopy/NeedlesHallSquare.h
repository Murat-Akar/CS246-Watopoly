#ifndef NEEDLESHALL_SQUARE_H
#define NEEDLESHALL_SQUARE_H

#include "ActionSquare.h"

class NeedlesHallSquare : public ActionSquare {
public:
    NeedlesHallSquare(int posn);
    virtual void applyAction(Player *p) override;
};

#endif // NEEDLESHALL_SQUARE_H
