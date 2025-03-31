#ifndef SLC_SQUARE_H
#define SLC_SQUARE_H

#include "ActionSquare.h"

class SLCSquare : public ActionSquare {
public:
    SLCSquare(int posn);
    virtual void applyAction(Player *p) override;
};

#endif
