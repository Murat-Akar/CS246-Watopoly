#ifndef TIMSLINE_SQUARE_H
#define TIMSLINE_SQUARE_H

#include "ActionSquare.h"

class TimsLineSquare : public ActionSquare {
private:
    int activeCups;
public:
    TimsLineSquare(int posn, int cups = 0);
    virtual void applyAction(Player *p) override;
};

#endif // TIMSLINE_SQUARE_H
