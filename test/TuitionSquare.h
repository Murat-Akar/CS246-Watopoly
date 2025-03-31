#ifndef TUITION_SQUARE_H
#define TUITION_SQUARE_H

#include "ActionSquare.h"

class TuitionSquare : public ActionSquare {
private:
    int tuitionAmount;
public:
    TuitionSquare(int posn, int tuitionAmount = 300);
    virtual void applyAction(Player *p) override;
};

#endif 
