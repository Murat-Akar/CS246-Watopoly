// CoopFeeSquare.h
#ifndef COOPFEE_SQUARE_H
#define COOPFEE_SQUARE_H

#include "ActionSquare.h"

class CoopFeeSquare : public ActionSquare {
private:
    int fee;
public:
    CoopFeeSquare(int posn, int fee = 150);
    virtual void applyAction(Player *p) override;
};

#endif 
