#include "ActionSquare.h"

ActionSquare::ActionSquare(const string &name, int posn)
    : Square(name, posn, 0, false) {
}

bool ActionSquare::landOn(Player *p) {
    applyAction(p);
    return true;
}
