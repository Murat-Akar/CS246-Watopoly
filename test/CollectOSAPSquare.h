#ifndef COLLECTOSAP_SQUARE_H
#define COLLECTOSAP_SQUARE_H

#include "ActionSquare.h"

class CollectOSAPSquare : public ActionSquare {
private:
    int collectAmount;
public:
    CollectOSAPSquare(int posn, int amount);
    virtual void applyAction(Player *p) override;
};

#endif 
